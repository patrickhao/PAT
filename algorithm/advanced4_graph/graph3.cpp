#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 1010;
const int INF = 1000000000;
int n, G[MAXN][MAXN];
int d[MAXN];
bool vis[MAXN] = {false};
vector<int> pre[MAXN]; //记录路径

void dijkstra(int s) {
    fill(d, d + MAXN, INF);
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

int main() {
    return 0;
}