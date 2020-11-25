#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;
const int MAXV = 512;
const int INF = 1000000000;
int G[MAXV][MAXV], bikeNum[MAXV];
int cmax, n, sp, m;
int d[MAXV];
bool vis[MAXV] = {false};
vector<int> pre[MAXV];

void dijkstra(int s) {
    fill(d, d + MAXV, INF);
    d[s] = 0;
    for (int i = 0; i <= n; i++) {
        int u = -1, MIN = INF;
        for (int j = 0; j <= n; j++) {
            if (!vis[j] && d[j] < MIN) {
                MIN = d[j];
                u = j;
            }
        }
        if (u == -1) {
            return;
        }
        vis[u] = true;
        for (int v = 0; v <= n; v++) {
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

int optValue = INF;
vector<int> path, pathTemp;

int ret = 0;
void dfs(int u) {
    if (u == 0) {
        pathTemp.push_back(u);
        int value = 0, maxRe = 0;
        for (int i = pathTemp.size() - 2; i >= 0; i--) {
            value = value + bikeNum[pathTemp[i]] - cmax / 2;
            if (-1 * value > maxRe) {
                maxRe = -1 * value;
            }
        }
        int retTemp = maxRe;
        for (int i = pathTemp.size() - 2; i >= 0; i--) {
            retTemp = retTemp + bikeNum[pathTemp[i]] - cmax / 2;
        }
        if (maxRe < optValue) {
            optValue = maxRe;
            path = pathTemp;
            ret = retTemp;
        } else if (maxRe == optValue && retTemp < ret) {
            path = pathTemp;
            ret = retTemp;
        }
        pathTemp.pop_back();
        return;
    }
    pathTemp.push_back(u);
    for (int v = 0; v < pre[u].size(); v++) {
        dfs(pre[u][v]);
    }
    pathTemp.pop_back();
}

void showPath(vector<int> p) {
    for (int i = p.size() - 1; i >= 0; i--) {
        printf("%d", p[i]);
        if (i != 0) {
            printf("->");
        }
    }
}

int main() {
    freopen("./sample_in/1018.txt", "r", stdin);
    scanf("%d %d %d %d", &cmax, &n, &sp, &m);
    fill(G[0], G[0] + MAXV * MAXV, INF);
    for (int i = 1; i <= n; i++) {
        scanf("%d", bikeNum + i);
    }
    for (int i = 0; i < m; i++) {
        int u, v, t;
        scanf("%d %d %d", &u, &v, &t);
        G[u][v] = t;
        G[v][u] = t;
    }
    dijkstra(0);
    dfs(sp);
    printf("%d ", optValue);
    showPath(path);
    printf(" %d\n", ret);

    return 0;
}