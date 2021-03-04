#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 50;

struct node {
    int aTime, pTime;

    node() {}
    node(int aTime, int pTime) : aTime(aTime), pTime(pTime) {}

    friend bool operator > (node a, node b) { return a.aTime > b.aTime; }
};

bool vip[MAXN] = {false};
int table[MAXN] = {0};
int n;

int strToNum(string s) {
    return ((s[0] - '0') * 10 + s[1] - '0') * 60 * 60 + ((s[3] - '0') * 10 + s[4] - '0') * 60 + (s[6] - '0') * 10 + s[7] - '0';
}

string preChange(int a) {
    return to_string(a / 10) + to_string(a % 10);
}

string numToStr(int a) {
    int h = a / 60 / 60;
    int m = a / 60 % 60;
    int s = a % 60;
    return preChange(h) + ":" + preChange(m) + ":" + preChange(s);
}

void putInfo(int curTime, int aTime) {
    cout << numToStr(aTime) << " " << numToStr(curTime) << " " << round((curTime - aTime) * 1.0 / 60) << endl;
}

int findTable(int tag) {
    if (tag == 0) {
        for (int i = 0; i < n; i++) if (table[i] == 0) return i;
    } else {
        for (int i = 0; i < n; i++) if (table[i] == 0 && vip[i]) return i;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    priority_queue<node, vector<node>, greater<node>> q1, q2;
    while (t--) {
        string s;
        int aTime, pTime, tag;
        cin >> s >> pTime >> tag;
        aTime = strToNum(s);
        pTime *= 60;
        pTime = min(2 * 60 * 60, pTime);
        if (tag == 1) q1.push(node(aTime, pTime));
        else q2.push(node(aTime, pTime));
    }
    int vNum;
    cin >> n >> vNum;
    while (vNum--) {
        int temp; cin >> temp;
        vip[temp - 1] = true;
    }

    vector<int> tNum(n, 0);
    int startTime = strToNum("08:00:00"), endTime = strToNum("21:00:00");
    int curTime = startTime;
    while (curTime < endTime) {
        if (q1.empty() && q2.empty()) break;
        while (findTable(0) != -1) {
            bool tag1 = !q1.empty(), tag2 = !q2.empty();
            node p1(endTime + 1, 0), p2(endTime + 1, 0);
            if (tag1) p1 = q1.top();
            if (tag2) p2 = q2.top();
            if (min(p1.aTime, p2.aTime) > curTime) break;
            if (tag1 && p1.aTime <= curTime && findTable(1) != -1) {
                int ind = findTable(1);
                table[ind] = p1.pTime;
                q1.pop();
                tNum[ind]++;
                putInfo(curTime, p1.aTime);
            } else {
                if (p1.aTime < p2.aTime) {
                    int ind = findTable(0);
                    table[ind] = p1.pTime;
                    q1.pop();
                    tNum[ind]++;
                    putInfo(curTime, p1.aTime);
                } else {
                    int ind = findTable(0);
                    table[ind] = p2.pTime;
                    q2.pop();
                    tNum[ind]++;
                    putInfo(curTime, p2.aTime);
                }
            }
        }
        curTime++;
        for (int i = 0; i < n; i++) if (table[i] != 0) table[i]--;
    }
    for (int i = 0; i < n; i++) {
        cout << tNum[i];
        cout << (i < n - 1 ? " " : "\n");
    }
    
    return 0;
}