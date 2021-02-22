#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int n, m, k, q;

int getIndex(const vector<queue<int>>& q) {
    int mx = INF;
    for (auto v : q) if (mx > v.size()) mx = v.size();
    for (int i = 0; i < q.size(); i++) if (q[i].size() == mx) return i;
    return 0;
}

int getNum(const vector<queue<int>>& q) {
    int ret = 0;
    for (auto v: q) ret += v.size();
    return ret;
}

int main() {
    cin >> n >> m >> k >> q;
    vector<int> a(k);
    for (int &v : a) cin >> v;

    int curTime = 0, ind = 0;
    vector<int> ans(k, 0), startTime(k, -1);
    vector<queue<int>> v(n);

    while (true) {
        curTime++;
        while (getNum(v) != n * m && ind < k) {
            int i = getIndex(v);
            v[i].push(ind++);
        }
        for (int i = 0; i < n; i++) {
            if (!v[i].empty()) {
                int cur = v[i].front();
                if (startTime[cur] == -1) startTime[cur] = curTime - 1;
                a[cur]--;
                if (a[cur] <= 0) {
                    v[i].pop();
                    ans[cur] = curTime;
                }
            }
        }
        if (getNum(v) == 0 && ind >= k) break;
        // for (auto v : startTime) cout << v << " ";
        // cout << endl;
    }

    while (q--) {
        int temp; cin >> temp;
        int t = ans[temp - 1], st = startTime[temp - 1];
        if (st >= 540) cout << "Sorry" << endl;
        else printf("%02d:%02d\n", 8 + t / 60, t % 60);
    }
    
    return 0;
}