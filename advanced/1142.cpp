#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int maxn = 256;
const int INF = 1000000000;
int G[maxn][maxn];
int nv, ne, m;
bool sta[maxn] = {false};

int judge(vector<int> arr) {
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr.size(); j++) {
            if (j != i) {
                if (G[arr[i]][arr[j]] == INF) {
                    return -1;
                }
            }
        }
    }
    for (int i = 1; i <= nv; i++) {
        if (!sta[i]) {
            bool flag = true;
            for (int j = 0; j < arr.size(); j++) {
                if (G[i][arr[j]] == INF) {
                    flag = false;
                }
            }
            if (flag) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    freopen("./sample_in/1142.txt", "r", stdin);
    fill(G[0], G[0] + maxn * maxn, INF);
    cin >> nv >> ne;
    while (ne--) {
        int u, v;
        cin >> u >> v;
        G[u][v] = 1;
        G[v][u] = 1;
    }
    cin >> m;
    while (m--) {
        fill(sta, sta + maxn, false);
        int k;
        cin >> k;
        vector<int> arr(k);
        for (int i = 0; i < k; i++) {
            cin >> arr[i];
            sta[arr[i]] = true;
        }
        int r = judge(arr);
        if (r == 1) {
            cout << "Yes" << endl;
        } else if (r == 0) {
            cout << "Not Maximal" << endl;
        } else {
            cout << "Not a Clique" << endl;
        }
    }

    return 0;
}