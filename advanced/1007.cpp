#include <cstdio>
#include <algorithm>

using namespace std;
struct elem {
    int v, pre;
};

int arr[10010];
elem dp[10010];

int main() {
    freopen("./sample_in/1007.txt", "r", stdin);
    int n;
    bool tag = false;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", arr + i);
        if (arr[i] >= 0) {
            tag = true;
        }
    }
    dp[0].v = arr[0];
    dp[0].pre = 0;
    for (int i = 1; i < n; i++) {
        if (dp[i - 1].v > 0) {
            dp[i].v = arr[i] + dp[i - 1].v;
            dp[i].pre = dp[i - 1].pre;
        } else {
            dp[i].v = arr[i];
            dp[i].pre = i;
        }
    }
    int index = 0;
    for (int i = 1; i < n; i++) {
        if (dp[i].v > dp[index].v) {
            index = i;
        }
    }
    if (tag) {
        printf("%d %d %d\n", dp[index].v, arr[dp[index].pre], arr[index]);
    } else {
        printf("0 %d %d\n", arr[0], arr[n - 1]);
    }

    return 0;
}