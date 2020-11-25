#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;
const int maxn = 1010;
int n, m, k;
int G[maxn][maxn];
int OG[maxn][maxn];
int vis[maxn];

void bfs(int s) {
    queue<int> q;
    q.push(s);
    vis[s] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v = 1; v <= n; v++) {
            if (!vis[v] && G[u][v] == 1) {
                q.push(v);
                vis[v] = true;
            }
        }
    }
}

int bfsTrave(int city) {
    fill(vis, vis + maxn, false);
    vis[city] = true;
    int ans = -1;
    for (int u = 1; u <= n; u++) {
        if (!vis[u]) {
            ans++;
            bfs(u);
        }
    }
    return ans;
}

int main() {
    freopen("./sample_in/1013.txt", "r", stdin);
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        G[u][v] = 1;
        G[v][u] = 1;
    }
    for (int i = 0; i < k; i++) {
        int city;
        scanf("%d", &city);
        printf("%d\n", bfsTrave(city));
    }

    return 0;
}