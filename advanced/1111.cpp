#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXV = 512;
const int INF = 1000000000;
int n, m, st, ed, G[MAXV][MAXV], T[MAXV][MAXV];
int d[MAXV], t[MAXV];
bool vis1[MAXV] = {false}, vis2[MAXV] = {false};
vector<int> pre1[MAXV], pre2[MAXV];
vector<int> path1, path2, pathTemp1, pathTemp2;
int optValue1 = INF, optValue2 = INF;

void dijkstra(int s) {
    fill(d, d + MAXV, INF);
    fill(t, t + MAXV, INF);
    d[s] = 0;
    t[s] = 0;
    for (int i = 0; i < n; i++) {
        int u1 = -1, u2 = -1, MIN1 = INF, MIN2 = INF;
        for (int j = 0; j < n; j++) {
            if (!vis1[j] && d[j] < MIN1) {
                u1 = j;
                MIN1 = d[j];
            }
            if (!vis2[j] && t[j] < MIN2) {
                u2 = j;
                MIN2 = t[j];
            }
        }
        if (u1 == -1 || u2 == -1) {
            return;
        }
        vis1[u1] = true;
        vis2[u2] = true;
        for (int v1 = 0; v1 < n; v1++) {
            if (!vis1[v1] && G[u1][v1] != INF) {
                if (d[u1] + G[u1][v1] < d[v1]) {
                    d[v1] = d[u1] + G[u1][v1];
                    pre1[v1].clear();
                    pre1[v1].push_back(u1);
                } else if (d[u1] + G[u1][v1] == d[v1]) {
                    pre1[v1].push_back(u1);
                }
            }
        }
        for (int v2 = 0; v2 < n; v2++) {
            if (!vis2[v2] && T[u2][v2] != INF) {
                if (t[u2] + T[u2][v2] < t[v2]) {
                    t[v2] = t[u2] + T[u2][v2];
                    pre2[v2].clear();
                    pre2[v2].push_back(u2);
                } else if (t[u2] + T[u2][v2] == t[v2]) {
                    pre2[v2].push_back(u2);
                }
            }
        }
    }
}

void dfs1(int u) {
    if (u == st) {
        pathTemp1.push_back(u);
        int value = 0;
        for (int i = pathTemp1.size() - 1; i > 0; i--) {
            int id = pathTemp1[i], idnext = pathTemp1[i - 1];
            value += T[id][idnext];
        }
        if (value < optValue1) {
            optValue1 = value;
            path1 = pathTemp1;
        }
        pathTemp1.pop_back();
        return;
    }
    pathTemp1.push_back(u);
    for (int i = 0; i < pre1[u].size(); i++) {
        dfs1(pre1[u][i]);
    }
    pathTemp1.pop_back();
}

void dfs2(int u) {
    if (u == st) {
        pathTemp2.push_back(u);
        int value = 0;
        for (int i = pathTemp2.size() - 1; i > 0; i--) {
            int id = pathTemp2[i], idnext = pathTemp2[i - 1];
            value += G[id][idnext];
        }
        if (value < optValue2) {
            optValue2 = value;
            path2 = pathTemp2;
        }
        pathTemp2.pop_back();
        return;
    }
    pathTemp2.push_back(u);
    for (int i = 0; i < pre2[u].size(); i++) {
        dfs2(pre2[u][i]);
    }
    pathTemp2.pop_back();
}

void showPath(vector<int> path) {
    for (int i = path.size() - 1; i >= 0; i--) {
        cout << path[i];
        if (i != 0) {
            cout << " -> ";
        }
    }
}

int main() {
    freopen("./sample_in/1111.txt", "r", stdin);
    int u, v, flag, l, ti;
    fill(G[0], G[0] + MAXV * MAXV, INF);
    fill(T[0], T[0] + MAXV * MAXV, INF);
    cin >> n >> m;
    while (m--) {
       cin >> u >> v >> flag >> l >> ti;
       G[u][v] = l;
       T[u][v] = ti;
       if (flag == 0) {
           G[v][u] = l;
           T[v][u] = ti;
       } 
    }
    cin >> st >> ed;
    dijkstra(st);
    dfs1(ed);
    dfs2(ed);

    bool same = true;
    if (path1.size() == path2.size()) {
        for (int i = 0; i < path1.size(); i++) {
            if (path1[i] != path2[i]) {
                same = false;
                break;
            }
        }
    } else {
        same = false;
    }
    if (same) {
        cout << "Distance = " << d[ed] << "; Time = " << t[ed] << ": ";
        showPath(path1);
        cout << endl;
    } else {
        cout << "Distance = " << d[ed] << ": ";
        showPath(path1);
        cout << endl;
        cout << "Time = " << t[ed] << ": ";
        showPath(path1);
        cout << endl;
    }

    return 0;
}