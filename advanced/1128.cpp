#include <iostream>
#include <set>

using namespace std;
const int maxn = 1010;
int arr[maxn] = {0};
int G[maxn][maxn] = {0};

int main() {
    freopen("./sample_in/1128.txt", "r", stdin);
    int k;
    scanf("%d", &k);
    while (k--) {
        fill(G[0], G[0] + maxn * maxn, 0);
        fill(arr, arr + maxn, 0);
        int n;
        set<int> es;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            int temp;
            scanf("%d", &temp);
            arr[i] = n - temp;
            G[n - temp][i] = 1;
            es.insert(temp);
        }
        if (es.size() != n) {
            printf("NO\n");
            continue;
        }
        bool tag = true;
        for (int i = 0; i < n; i++) {
            int px = arr[i], py = i;
            int j = 1;
            if (tag) {
                while (px - j >= 0 && py - j >= 0) {
                    if (G[px - j][py - j] == 1) {
                        tag = false;
                        break;
                    }
                    j++;
                }
            }
            j = 1;
            if (tag) {
                while (px - j >= 0 && py + j < n) {
                    if (G[px - j][py + j] == 1) {
                        tag = false;
                        break;
                    }
                    j++;
                }
            }
            j = 1;
            if (tag) {
                while (px + j < n && py - j >= 0) {
                    if (G[px + j][py - j] == 1) {
                        tag = false;
                        break;
                    }
                    j++;
                }
            }
            j = 1;
            if (tag) {
                while (px + j < n && py + j < n) {
                    if (G[px + j][py + j] == 1) {
                        tag = false;
                        break;
                    }
                    j++;
                }
            }
        }
        if (tag) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}