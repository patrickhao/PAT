#include <cstdio>

using namespace std;
const int maxn = 10010;
int n;
int G[maxn][maxn];
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
        for (int i = 1; i <= n; i++) {
            if (table[i] == 1) {
                printf("%d\n", i);
            }
        }
    } else {
        printf("Error: %d components", tag);
    }
    return 0;
}