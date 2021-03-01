#include <bits/stdc++.h>
using namespace std;
int n, m;
const int MAXN = 1e4 + 50;
vector<int> Adj[MAXN];
vector<int> inDegree, inDegree2;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    inDegree.resize(n + 1, 0);
    while (m--) {
        int u, v; cin >> u >> v;
        Adj[u].push_back(v);
        inDegree[v]++;
    }

    int k; cin >> k;
    vector<int> ans;
    for (int i = 0; i < k; i++) {
        inDegree2 = inDegree;
        vector<int> temp(n);
        for (int &v : temp) cin >> v;
        for (auto u : temp) {
            if (inDegree2[u] != 0) {
                ans.push_back(i);
                break;
            }
            for (auto v : Adj[u]) {
                inDegree2[v]--;
            }
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
        cout << (i < ans.size() - 1 ? " " : "\n");
    }
    return 0;
}