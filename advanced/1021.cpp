#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 50;
int n;
bool G[MAXN][MAXN] = {false};
bool hashTable[MAXN] = {false};
bool vis[MAXN] = {false};
int father[MAXN];

int findFather(int a) {
    int x = a;
    while (x != father[x]) x = father[x];

    while (a != x) {
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}

void Union(int a, int b) {
    int fa = findFather(a);
    int fb = findFather(b);
    if (fa != fb) father[fa] = fb;
}

int bfs(int i) {
    queue<int> q;
    q.push(i);
    vis[i] = true;
    int ret = 0;
    while (!q.empty()) {
        int cnt = q.size();
        ret++;
        while (cnt--) {
            int u = q.front();
            q.pop();
            for (int v = 1; v <= n; v++) {
                if (G[u][v] && vis[v] == false) {
                    vis[v] = true;
                    q.push(v);
                    Union(i, v);
                }
            }
        }
    }
    return ret;
}

vector<int> ans;
int maxDepth = 0;
void bfsTrave() {
    for (int i = 1; i <= n; i++) {
        fill(vis, vis + MAXN, false);
        int depth = bfs(i);
        if (depth > maxDepth) {
            maxDepth = depth;
            ans.clear();
            ans.push_back(i);
        } else if (depth == maxDepth) {
            ans.push_back(i);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    for (int i = 0; i < MAXN; i++) father[i] = i;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        G[u][v] = true; G[v][u] = true;
    }
    bfsTrave();
    
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (father[i] == i) cnt++;
    }
    if (cnt > 1) {
        cout << "Error: " << cnt << " components" << endl;
    } else {
        for (auto v : ans) cout << v << endl;
    }
    
    return 0;
}