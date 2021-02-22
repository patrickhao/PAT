#include <bits/stdc++.h>
using namespace std;

struct elem {
    int s, t;

    elem() {}
    elem(int s, int t) : s(s), t(t) {}

    friend bool operator < (elem a, elem b) {
        return a.s < b.s;
    }
};

int n, k;

int change(string t) {
    int h, m, s;
    h = stoi(t.substr(0, 2));
    m = stoi(t.substr(3, 2));
    s = stoi(t.substr(6, 2));
    return h * 60 * 60 + m * 60 + s;
}

int getIndex(const vector<int>& a) {
    for (int i = 0; i < a.size(); i++) if (a[i] == 0) return i;
    return -1;
}

bool judge(const vector<int>& a) {
    for (int i = 0; i < a.size(); i++) if (a[i] != 0) return false;
    return true;
}

int main() {
    cin >> n >> k;
    int start = change("08:00:00"), end = change("17:00:00");
    vector<elem> data;
    for (int i = 0; i < n; i++) {
        string s;
        elem e;
        cin >> s >> e.t;
        e.s = change(s);
        e.t *= 60;
        data.push_back(e);
    }
    sort(data.begin(), data.end());
    int num = 0;
    for (auto v : data) {
        if (v.s > end) break;
        num++;
    }

    int curTime = 0, ind = 0, allTime = 0;
    vector<int> a(k, 0);
    while (true) {
        if (ind >= num && judge(a)) break;
        curTime++;
        if (curTime >= start) {
            while (getIndex(a) != -1 && ind < num && curTime >= data[ind].s) {
                a[getIndex(a)] = data[ind].t;
                allTime += (curTime - data[ind].s);
                // printf("%d, %d, %d\n", curTime, data[ind].s, data[ind].t);
                ++ind;
            }
        }
        for (int &v : a) if (v != 0) v--;
    }
    printf("%.1f\n", allTime * 1.0 / 60 / num);
    
    return 0;
}