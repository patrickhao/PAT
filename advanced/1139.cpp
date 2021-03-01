#include <bits/stdc++.h>
using namespace std;
#define MP make_pair
typedef pair<int, int> PII;
const int MAXN = 1e5;
bool gender[MAXN] = {false};
vector<int> Adj[MAXN];
int n, m;

int a, b;
bool flag[4];
vector<PII> ans;
vector<int> temp;
void dfs(int cur, int depth) {
    // printf("cur: %04d, depth: %d\n", cur, depth);
    if (depth == 3) {
        if (cur == b) ans.push_back(MP(temp[0], temp[1]));
        return;
    }
    if (gender[cur] != flag[depth]) return;
    for (auto v : Adj[cur]) {
        temp.push_back(v);
        dfs(v, depth + 1);
        temp.pop_back();
    }
}

void solve() {
    cin >> a >> b;
    a = abs(a); b = abs(b);
    flag[0] = flag[1] = gender[a];
    flag[2] = flag[3] = gender[b];
    ans.clear(); temp.clear();
    dfs(a, 0);
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto v : ans) cout << v.first << " " << v.second << endl;
}

int main() {
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        gender[abs(u)] = u > 0;
        gender[abs(v)] = v > 0;
        u = abs(u); v = abs(v);
        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }

    int t; cin >> t;
    while (t--) solve();
    
    return 0;
}