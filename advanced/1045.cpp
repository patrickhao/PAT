#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 10010;
int n, m, l;
int color[maxn], hashTable[maxn], dp[maxn];

int main() {
    freopen("./sample_in/1045.txt", "r", stdin);
    scanf("%d", &n);
    scanf("%d", &m);
    fill(hashTable, hashTable + maxn, -1);
    for (int i = 0; i < m; i++) {
        int temp;
        scanf("%d", &temp);
        hashTable[temp] = i;
    }
    scanf("%d", &l);
    int ic = 0;
    for (int i = 0; i < l; i++) {
        int temp;
        scanf("%d", &temp);
        if (hashTable[temp] != -1) {
            color[ic++] = hashTable[temp];
        }
    }

    int ans = -1;
    for (int i = 0; i < ic; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (color[j] <= color[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
            }
        }
        ans = max(ans, dp[i]);
    }

    printf("%d\n", ans);

    return 0;
}