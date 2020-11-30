#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int maxn = 10010;
const int INF = 1000000000;
struct node {
    int v;
    int line;

    node(int _v, int _line) : v(_v), line(_line) {}
};
vector<node> Adj[maxn];
int d[maxn];
bool vis[maxn] = {false};
vector<int> pre;

void dijkstra(int s) {
    fill(d, d + maxn, INF);
    d[s] = 0;
    for (int i = 0; i < maxn; i++) {
        int u = -1, MIN = INF;
        for (int j = 0; i < maxn; j++) {
            if (!vis[j] && d[j] < MIN) {
                MIN = d[j];
                u = j;
            }
        }
        if (u == -1) {
            return;
        }
        vis[u] == true;
        for (int j = 0; j < Adj[u].size(); j++) {
            int v = Adj[u][j].v;
            if (!vis[v]) {
                if (d[u] + 1 < d[v]) {
                    d[v] = d[u] + 1;
                    pre.clear();
                    pre.push_back(u);
                } else if (d[u] + 1 == d[v]) {
                    pre.push_back(u);
                }
            }
        }
    }
}


int main() {
    freopen("./sample_in/1131.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int m, pre, cur;
        cin >> m >> pre;
        m--;
        while (m--) {
            cin >> cur;
            Adj[pre].push_back(node(cur, i));
            Adj[cur].push_back(node(pre, i));
            pre = cur;
        }
    }
    dijkstra(0);
    return 0;
}