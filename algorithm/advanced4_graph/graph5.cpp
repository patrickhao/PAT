#include <vector>
#include <algorithm>

using namespace std;
const int MAXN = 1010;
const int INF = 1000000000;

struct Node {
    int v, dis;
};

//邻接矩阵
int n, G[MAXN][MAXN], d[MAXN];
bool vis[MAXN] = {false};

int prim1(int s) {
    int ans = 0;
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
            return -1;
        }
        vis[u] = true;
        ans += d[u];
        for (int v = 0; v < n; v++) {
            if (!vis[v] && G[u][v] != INF && G[u][v] < d[v]) {
                d[v] = G[u][v];
            }
        }
    }
    return ans;
}

//临界表
vector<Node> Adj[MAXN];
int prim2(int s) {
    fill(d, d + MAXN, INF);
    d[s] = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int u = -1, MIN = INF;
        for (int j = 0; j < n; j++) {
            if (!vis[j] && d[j] < MIN) {
                MIN = d[j];
                u = j;
            }
        }
        if (u == -1) {
            return -1;
        }
        vis[u] = true;
        ans += d[u];
        for (int j = 0; j < Adj[u].size(); j++) {
            int v = Adj[u][j].v;
            if (!vis[v] && Adj[u][j].dis < d[v]) {
                d[v] = Adj[u][j].dis;
            }
        }
    }
    return ans;
}

int main() {
    return 0;
}