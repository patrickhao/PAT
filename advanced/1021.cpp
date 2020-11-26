#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;
const int maxn = 10010;
int n;
int G[maxn][maxn];
int D[maxn] = {0}, ans[maxn] = {0};
bool vis[maxn] = {false};

void dfs(int u) {
    vis[u] = true;
    for (int v = 1; v <= n; v++) {
        if (!vis[v] && G[u][v] == 1) {
            dfs(v);
        }
    }
}

int dfsTrave() {
    int ans = 0;
    for (int u = 1; u <= n; u++) {
        if (!vis[u]) {
            ans++;
            dfs(u);
        }
    }
    return ans;
}

int bfs(int s) {
    int d = 0;
    fill(vis, vis + maxn, false);
    queue<int> q;
    q.push(s);
    D[s] = 0;
    vis[s] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v = 1; v <= n; v++) {
            if (!vis[v] && G[u][v] == 1) {
                vis[v] = true;
                q.push(v);
                D[v] = D[u] + 1;
                if (D[v] > d) {
                    d = D[v];
                }
            }
        }
    }
    return d;
}

int depth = 0;
void bfsTrave() {
    for (int i = 1; i <= n; i++) {
        ans[i] = bfs(i);
        if (ans[i] > depth) {
            depth = ans[i];
        }
    }
}

int main() {
    freopen("./sample_in/1021.txt", "r", stdin);
    scanf("%d", &n);
    int table[maxn] = {0};
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        G[u][v] = 1;
        G[v][u] = 1;
        table[u]++;
        table[v]++;
    }
    int tag = dfsTrave();
    if (tag == 1) {
        bfsTrave();
        for (int i = 1; i <= n; i++) {
            if (ans[i] == depth) {
                printf("%d\n", i);
            }
        }
    } else {
        printf("Error: %d components", tag);
    }
    return 0;
}