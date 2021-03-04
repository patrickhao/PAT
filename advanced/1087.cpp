#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int MAXN = 300;
int G[MAXN][MAXN];
int weight[MAXN] = {0};
map<string, int> cityToIndex;
map<int, string> indexToCity;
int n, k, ind = 0;
string start;

int getIndex(string s) {
    if (cityToIndex.find(s) != cityToIndex.end()) return cityToIndex[s];
    else {
        cityToIndex[s] = ind;
        return ind++;
    }
}

bool vis[MAXN] = {false};
vector<int> pre[MAXN];
int d[MAXN];
void dijkstra(int s) {
    fill(d, d + MAXN, INF);
    d[s] = 0;
    for (int i = 0; i < n; i++) {
        int u = -1, MIN = INF;
        for (int j = 0; j < n; j++) {
            if (vis[j] == false && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }
        if (u == -1) return;
        vis[u] = true;
        for (int v = 0; v < n; v++) {
            if (vis[v] == false && G[u][v] != INF) {
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

vector<int> ans, pathTemp;
int cnt = 0, optValue = -INF;
void dfs(int u) {
    if (u == getIndex(start)) {
        cnt++;
        pathTemp.push_back(u);
        int sum = 0;
        for (auto v : pathTemp) sum += weight[v];
        if (sum > optValue) {
            ans = pathTemp;
            optValue = sum;
        } else if (sum == optValue && pathTemp.size() < ans.size()) ans = pathTemp;
        pathTemp.pop_back();
        return;
    }

    pathTemp.push_back(u);
    for (auto v : pre[u]) {
        dfs(v);
    }
    pathTemp.pop_back();
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    fill(G[0], G[0] + MAXN * MAXN, INF);
    cin >> n >> k >> start;
    indexToCity[getIndex(start)] = start;
    for (int i = 0; i < n - 1; i++) {
        string s;
        int w;
        cin >> s >> w;
        weight[getIndex(s)] = w;
        indexToCity[getIndex(s)] = s;
    }
    for (int i = 0; i < k; i++) {
        string s1, s2;
        int d;
        cin >> s1 >> s2 >> d;
        int u = getIndex(s1), v = getIndex(s2);
        G[u][v] = G[v][u] = d;
    }
    dijkstra(getIndex(start));
    dfs(getIndex("ROM"));
    cout << cnt << " " << d[getIndex("ROM")] << " " << optValue << " " << optValue / (ans.size() - 1) << endl;
    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << indexToCity[ans[i]];
        cout << (i > 0 ? "->" : "\n");
    }
    
    return 0;
}