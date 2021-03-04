#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int MAXN = 1e3 + 50;

int n, m, k, ds;
int G[MAXN][MAXN];

int change(string s) {
    if (s[0] == 'G') return stoi(s.substr(1, s.length() - 1)) + n;
    else return stoi(s);
}

bool vis[MAXN];
int d[MAXN];
void dijkstra(int s) {
    fill(vis, vis + MAXN, false);
    fill(d, d + MAXN, INF);
    d[s] = 0;
    for (int i = 1; i <= n + m; i++) {
        int u = -1, MIN = INF;
        for (int j = 1; j <= n + m; j++) {
            if (vis[j] == false && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }
        if (u == -1) return;
        vis[u] = true;
        for (int v = 1; v <= m + n; v++) {
            if (G[u][v] != INF && vis[v] == false && d[u] + G[u][v] < d[v]) {
                d[v] = d[u] + G[u][v];
            }
        }
    }
}

int main() {
    fill(G[0], G[0] + MAXN * MAXN, INF);
    for (int i = 0; i < MAXN; i++) G[i][i] = 0;
    cin >> n >> m >> k >> ds;
    for (int i = 0; i < k; i++) {
        string su, sv;
        int u, v, dist;
        cin >> su >> sv >> dist;
        u = change(su); v = change(sv);
        G[u][v] = G[v][u] = min(dist, G[u][v]);
    }

    int ansInd = -1, ansMin = -1, ansSum = -1;
    for (int i = n + 1; i <= n + m; i++) {
        dijkstra(i);
        int mx = *max_element(d + 1, d + n + 1);
        int mn = *min_element(d + 1, d + n + 1);
        int sum = accumulate(d + 1, d + n + 1, 0);
        if (mx <= ds && mn > ansMin)  {
            ansMin = mn;
            ansInd = i;
            ansSum = sum;
        } else if (mx <= ds && mn == ansMin && sum < ansSum) {
            ansInd = i;
            ansSum = sum;
        }
    }
    if (ansInd == -1) cout << "No Solution" << endl;
    else {
        cout << "G" << ansInd - n << endl;
        printf("%.1f %.1f\n", (double)ansMin, ansSum * 1.0 / n);
        // printf("%.1f %.1f\n", (double)ansMin, (round(ansSum * 1.0 / n * 10) * 1.0 / 10));
    }

    return 0;
}