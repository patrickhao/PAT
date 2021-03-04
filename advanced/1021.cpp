#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 50;
bool G[MAXN][MAXN] = {false};
int n;

bool vis[MAXN] = {false};
void bfs(int s) {
    queue<int> q;
    vis[s] = true;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v = 1; v <= n; v++) {
            if (G[u][v] && vis[v] == false) {
                q.push(v);
                vis[v] = true;
            }
        }
    }
}

int bfsTrave() {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (vis[i] == false) {
            bfs(i);
            cnt++;
        }
    }
    return cnt;
}

vector<int> arr;
int maxDepth = 0;
void dfs(int u, int depth) {
    if (depth == maxDepth) {
        arr.push_back(u);
    } else if (depth > maxDepth) {
        arr.clear();
        arr.push_back(u);
        maxDepth = depth;
    }
    for (int v = 1; v <= n; v++) {
        if (G[u][v] && vis[v] == false) {
            vis[v] = true;
            dfs(v, depth + 1);
        }
    }
}

void dfsTrave(int s) {
    fill(vis, vis + MAXN, false);
    vis[s] = true;
    arr.clear();
    maxDepth = 0;
    dfs(s, 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        G[u][v] = true; G[v][u] = true;
    }
    int cnt = bfsTrave();
    if (cnt != 1) cout << "Error: " << cnt << " components" << endl;
    else {
        set<int> ans;
        dfsTrave(1);
        for (auto v : arr) ans.insert(v);
        int temp = arr[0];
        dfsTrave(temp);
        for (auto v : arr) ans.insert(v);
        for (auto v : ans) cout << v << endl;
    }    

    return 0;
}