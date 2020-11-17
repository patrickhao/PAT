#include <cstdio>
#include <vector>

using namespace std;

const int MAXV = 1000;
const int INF = 1000000000;

//邻接表版
int n, G[MAXV][MAXV];
bool vis[MAXV] = {false};

void dfs1(int u, int depth) {
    vis[u] = true;
    for(int v = 0; v < n; v++) {
        if(vis[v] == false && G[u][v] != INF) {
            dfs1(v, depth + 1);
        }
    }
}

//邻接表版
vector<int> Adj[MAXV];
int n;

void dfs2(int u, int depth) {
    vis[u] = true;
    for(int i = 0; i < Adj[u].size(); i++) {
        int v = Adj[u][i];
        if(vis[v] == false) {
            dfs2(v, depth + 1);
        }
    }
}

void dfsTrave() {
    for(int u = 0; u < n; u++) {
        if(!vis[u]) {
            dfs1(u, 1);
            //dfs2(u, 1);
        }
    }
}

void dfs2(int u, int depth) {
    if(vis[u]) {
        return;
    }
}

int main() {
    return 0;
}