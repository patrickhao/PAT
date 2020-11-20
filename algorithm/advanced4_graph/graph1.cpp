#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

const int MAXN = 1000;
const int INF = 1000000000;

struct Node {
    int v;
    int layer;

    Node(int _v, int _layer) : v(_v), layer(_layer) {}
};

//邻接矩阵版--dfs
int n, G[MAXN][MAXN];
bool vis[MAXN] = {false};

void dfs1(int u, int depth) {
    vis[u] = true;
    for(int v = 0; v < n; v++) {
        if(vis[v] == false && G[u][v] != INF) {
            dfs1(v, depth + 1);
        }
    }
}

//邻接表版--dfs
vector<int> Adj[MAXN];
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

//邻接矩阵版--bfs
bool inq[MAXN] = {false};
void bfs1(int u) {
    queue<int> q;
    q.push(u);
    inq[u] = true;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int v = 0; v < n; v++) {
            if(!inq[v] && G[u][v] != INF) {
                q.push(v);
                inq[v] = true;
            }
        }
    }
}

//邻接表版--bfs
void bfs2(int u) {
    queue<int> q;
    q.push(u);
    inq[u] = true;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int i = 0; i < Adj[u].size(); i++) {
            int v = Adj[u][i];
            if(!inq[v]) {
                q.push(v);
                inq[v] = true;
            }
        }
    }
}

void bfsTrave() {
    for(int u = 0; u < n; u++) {
        if(!inq[u]) {
            bfs1(u);
            //bfs2(u);
        }
    }
}

//bfs--layer
vector<Node> Adj2[MAXN];
void bfs3(int s) {
    queue<Node> q;
    q.push(Node(s, 0));
    inq[s] = true;
    while(!q.empty()) {
        Node topNode = q.front();
        q.pop();
        int u = topNode.v;
        for(int i = 0; i < n; i++) {
            Node next = Adj2[u][i];
            next.layer = topNode.layer + 1;
            if(!inq[next.v]) {
                q.push(next);
                inq[next.v] = true;
            }
        }
    }
}

int main() {
    return 0;
}