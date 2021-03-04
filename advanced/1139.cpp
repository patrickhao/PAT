#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 50;
map<int, bool> mp;
vector<int> Adj[MAXN];
int n, m;

int main() {
    cin >> n >> m;
    while (m--) {
        string s1, s2; cin >> s1 >> s2;
        int u = abs(stoi(s1)), v = abs(stoi(s2));
        if (s1.length() == s2.length()) {
            Adj[u].push_back(v);
            Adj[v].push_back(u);
        }
        mp[10000 * u + v] = mp[10000 * v + u] = true;
    }
    int k; cin >> k;
    while (k--) {
        vector<pair<int, int>> ans;
        int a, b; cin >> a >> b;
        a = abs(a); b = abs(b);
        for (auto i : Adj[a]) {
            for (auto j : Adj[b]) {
                if (i == b || j == a) continue;
                if (mp[i * 10000 + j] || mp[j * 10000 + i]) ans.push_back(make_pair(i, j));
            }
        }
        sort(ans.begin(), ans.end()); 
        cout << ans.size() << endl;
        for (auto v : ans) printf("%04d %04d\n", v.first, v.second);
    }

    return 0;
}