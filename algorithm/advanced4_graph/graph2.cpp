#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
const int MAXN = 1010;
const int INF = 1000000000;
struct Node {
    int v, dis;
};

int n, G[MAXN][MAXN];
int d[MAXN];
bool vis[MAXN] = {false};

void dijkstra1(int s) {
    fill(d, d + MAXN, INF);
    d[s] = 0;
    for (int i = 0; i < n; i++) {
        int u = -1, m = INF;
        for (int j = 0; j < n; j++) {
            if (!vis[j] && d[j] < m) {
                m = d[j];
                u = j;
            }
        }
        if (u == -1) {
            return;
        }
        vis[u] = true;
        for (int v = 0; v < n; v++) {
            if (!vis[v] && G[u][v] != INF && d[u] + G[u][v] < d[v]) {
                d[v] = d[u] + G[u][v];
            }
        }
    }
}

vector<Node> Adj[MAXN];

void dijkstra2(int s) {
    fill(d, d + MAXN, INF);
    d[s] = 0;
    for (int i = 0; i < n; i++) {
        int u = -1, m = INF;
        for (int j = 0; j < n; j++) {
            if (!vis[j] && d[j] < m) {
                m = d[j];
                u = j;
            }
        }
        if (u == -1) {
            return;
        }
        vis[u] = true;
        for(int j = 0; j < Adj[u].size(); j++) {
            int v = Adj[u][j].v;
            if (!vis[v] && d[u] + Adj[u][j].dis < d[v]) {
                d[v] = d[u] + Adj[u][j].dis;
            }
        }
    }
}


int main() {
    return 0;
}