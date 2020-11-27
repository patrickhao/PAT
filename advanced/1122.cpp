#include <cstdio>
#include <algorithm>
#include <vector>

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
        scanf("%d", &num);
        vector<int> arr(num);
        for (int i = 0; i < num; i++) {
            scanf("%d", &arr[i]);
        }
        if (num == n + 1 && arr[0] == arr[num - 1]) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }

    }

    return 0;
}