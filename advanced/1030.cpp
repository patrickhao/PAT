#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXV = 1010;
const int INF = 1000000000;

int m, n, st, ed, G[MAXV][MAXV], C[MAXV][MAXV];
vector<int> pre[MAXV];

int d[MAXV];
bool vis[MAXV];

void dijkstra(int s) {
    fill(d, d + MAXV, INF);
    d[s] = 0;
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
                    pre[v].clear();
                    pre[v].push_back(u);
                } else if (d[u] + G[u][v] == d[v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }
}

int optValue = INF, totalDist = INF;
vector<int> path, tempPath;

void dfs(int u) {
    if (u == st) {
        tempPath.push_back(u);
        int value = 0, dist = 0;
        for (int i = tempPath.size() - 1; i > 0; i--) {
            int id = tempPath[i], idnext = tempPath[i - 1];
            value += C[id][idnext];
            dist += G[id][idnext];
        }
        if (value < optValue) {
            path = tempPath;
            totalDist = dist;
            optValue = value;
        }
        tempPath.pop_back();
        return;
    }

    tempPath.push_back(u);
    for (int i = 0; i < pre[u].size(); i++) {
        dfs(pre[u][i]);
    }
    tempPath.pop_back();
}

int main() {
    freopen("./sample_in/1030.txt", "r", stdin);
    int u, v, dist, cost;
    fill(G[0], G[0] + MAXV * MAXV, INF);
    fill(C[0], C[0] + MAXV * MAXV, INF);
    scanf("%d %d %d %d", &n, &m, &st, &ed);
    while (m--) {
        scanf("%d %d %d %d", &u, &v, &dist, &cost);
        G[u][v] = G[v][u] = dist;
        C[u][v] = C[v][u] = cost;
    }
    dijkstra(st);
    dfs(ed);
    for (int i = path.size() - 1; i >= 0; i--) {
        printf("%d ", path[i]);
    }
    printf("%d %d", totalDist, optValue);

    return 0;
}