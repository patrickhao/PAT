#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXV = 512;
const int INF = 1000000000;
int m, n, s, e, G[MAXV][MAXV], r[MAXV], nums[MAXV], d[MAXV], re[MAXV];
bool vis[MAXV] = {false};

void dijkstra(int s) {
    fill(d, d + MAXV, INF);
    fill(re, re + MAXV, 0);
    fill(nums, nums + MAXV, 0);
    d[s] = 0;
    re[s] = r[s];
    nums[s] = 1;
    for (int i = 0; i < n; i++) {
        int u = -1, MIN = INF;
        for (int j = 0; j < n; j++) {
            if (!vis[j] && d[j] < MIN) {
                MIN = d[j];
                u = j;
            }
        }
        if (u == -1) {
            return;
        }
        vis[u] = true;
        for (int v = 0; v < n; v++) {
            if (!vis[v] && G[u][v] != INF) {
                if (d[u] + G[u][v] < d[v]) {
                    d[v] = d[u] + G[u][v];
                    nums[v] = nums[u];
                    re[v] = re[u] + r[v];
                } else if (d[u] + G[u][v] == d[v]) {
                    nums[v] += nums[u];
                    if (re[u] + r[v] > re[v]) {
                        re[v] = re[u] + r[v];
                    }
                }
            }
        }
    }
}

int main() {
    freopen("./sample_in/1003.txt", "r", stdin);
    int u, v, w;
    fill(G[0], G[0] + MAXV * MAXV, INF);
    scanf("%d %d %d %d", &n, &m, &s, &e);
    for (int i = 0; i < n; i++) {
        scanf("%d", r + i);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        G[u][v] = G[v][u] = w;
    }
    dijkstra(s);
    printf("%d %d\n", nums[e], re[e]);

    return 0;
}