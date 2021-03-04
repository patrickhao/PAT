#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int MAXN = 550;

struct node {
    int v, l, t;
    
    node() {}
    node(int v, int l, int t) : v(v), l(l), t(t) {}
};
vector<node> Adj[MAXN];
int n, m, st, ed;

int pre1[MAXN], pre2[MAXN], d1[MAXN], d2[MAXN];
bool vis1[MAXN] = {false}, vis2[MAXN] = {false};
int ans1, ans2;
void dijkstra1(int st, int ed) {
    for (int i = 0; i < n; i++) pre1[i] = i;
    fill(d1, d1 + MAXN, INF);
    fill(d2, d2 + MAXN, INF);
    d1[st] = d2[st] = 0;
    for (int i = 0; i < n; i++) {
        int u = -1, MIN = INF;
        for (int j = 0; j < n; j++) {
            if (vis1[j] == false && d1[j] < MIN) {
                u = j;
                MIN = d1[j];
            }
        }
        if (u == -1) return;
        vis1[u] = true;
        for (int j = 0; j < Adj[u].size(); j++) {
            int v = Adj[u][j].v;
            if (vis1[v] == false) {
                if (d1[u] + Adj[u][j].l < d1[v]) {
                    pre1[v] = u;
                    d1[v] = d1[u] + Adj[u][j].l;
                    d2[v] = d2[u] + Adj[u][j].t;
                } else if (d1[u] + Adj[u][j].l == d1[v] && d2[u] + Adj[u][j].t < d2[v]) {
                    pre1[v] = u;
                    d2[v] = d2[u] + Adj[u][j].t;
                }
            }
        }
    }
    ans1 = d1[ed];
}

int nums[MAXN] = {0};
void dijkstra2(int st, int ed) {
    for (int i = 0; i < n; i++) pre2[i] = i;
    fill(d1, d1 + MAXN, INF);
    d1[st] = 0; nums[st] = 1;
    for (int i = 0; i < n; i++) {
        int u = -1, MIN = INF;
        for (int j = 0; j < n; j++) {
            if (vis2[j] == false && d1[j] < MIN) {
                u = j;
                MIN = d1[j];
            }
        }
        if (u == -1) return;
        vis2[u] = true;
        for (int j = 0; j < Adj[u].size(); j++) {
            int v = Adj[u][j].v;
            if (vis2[v] == false) {
                if (d1[u] + Adj[u][j].t < d1[v]) {
                    pre2[v] = u;
                    d1[v] = d1[u] + Adj[u][j].t;
                    nums[v] = nums[u] + 1;
                } else if (d1[u] + Adj[u][j].t == d1[v] && nums[u] + 1 < nums[v]) {
                    pre2[v] = u;
                    nums[v] = nums[u] + 1;
                }
            }
        }
    }
    ans2 = d1[ed];
}

vector<int> path1, path2;
void dfs1(int u, int st) {
    if (u == st) {
        path1.push_back(u);
        return;
    }
    path1.push_back(u);
    dfs1(pre1[u], st);
}

void dfs2(int u, int st) {
    if (u == st) {
        path2.push_back(u);
        return;
    }
    path2.push_back(u);
    dfs2(pre2[u], st);
}

void putPath(vector<int> path) {
    for (int i = path.size() - 1; i >= 0; i--) {
        cout << path[i];
        cout << (i > 0 ? " -> " : "\n");
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    while (m--) {
        int u, v, tag, l, t; cin >> u >> v >> tag >> l >> t;
        if (tag == 0) {
            Adj[u].push_back(node(v, l, t));
            Adj[v].push_back(node(u, l, t));
        } else Adj[u].push_back(node(v, l, t));
    }
    cin >> st >> ed;
    dijkstra1(st, ed);
    dijkstra2(st, ed);
    dfs1(ed, st);
    dfs2(ed, st);
    if (path1 == path2) {
        cout << "Distance = " << ans1 << "; Time = " << ans2 << ": ";
        putPath(path1);
    } else {
        cout << "Distance = " << ans1 << ": ";
        putPath(path1);
        cout << "Time = " << ans2 << ": ";
        putPath(path2);
    }

    return 0;
}