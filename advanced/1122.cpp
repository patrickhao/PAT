#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;
const int MAXV = 300;
int G[MAXV][MAXV];
int n, m;

int main() {
    freopen("./sample_in/1122.txt", "r", stdin);
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        G[u][v] = 1;
        G[v][u] = 1;
    }
    int k;
    scanf("%d", &k);
    while (k--) {
        int num;
        bool sta = true;
        scanf("%d", &num);
        vector<int> arr(num);
        set<int> se;
        for (int i = 0; i < num; i++) {
            scanf("%d", &arr[i]);
            se.insert(arr[i]);
        }
        for (int i = 0; i < num - 1; i++) {
            if (G[arr[i]][arr[i + 1]] != 1) {
                sta = false;
                break;
            }
        }
        if (se.size() == n && sta && num == n + 1 && arr[0] == arr[num - 1]) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }

    }

    return 0;
}