#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
int n, k, p;
vector<int> ans, path;
int ansValue = 0;

void dfs(int index, int count, int sum, int pSum) {
    if (sum == n && count == k) {
        if (pSum > ansValue) {
            ansValue = pSum;
            ans = path;
        }
        return;
    }

    if (sum > n || count > k) {
        return;
    }

    if (index > 0) {
        path.push_back(index);
        dfs(index, count + 1, sum + pow(index, p), pSum + index);   
        path.pop_back();
        dfs(index - 1, count, sum, pSum);
    }
}

int main() {
    freopen("./sample_in/1103.txt", "r", stdin);
    scanf("%d %d %d", &n, &k, &p);
    dfs((int)sqrt(n), 0, 0, 0);
    if (ans.size() != 0) {
        printf("%d = ", n);
        for (int i = 0; i < k; i++) {
            printf("%d^%d", ans[i], p);
            if (i < k - 1) {
                printf(" + ");
            } else {
                printf("\n");
            }
        }
    } else {
        printf("Impossible\n");
    }

    return 0;
}