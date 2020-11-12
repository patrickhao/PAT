#include <cstdio>
#include <vector>

using namespace std;

const int maxn = 3;
int n = 3, k = 5, x = 17, maxSumSqu = -1, A[maxn] = {1, 4, 7};
vector<int> temp, ans;

//可以重复选
void dfs(int index, int nowK, int sum, int sumSqu) {
    if(nowK == k && sum == x) {
        if(sumSqu > maxSumSqu) {
            maxSumSqu = sumSqu;
            ans = temp;
        }
        return;
    }
    if(index == n || nowK > k || sum > x) {
        return;
    }

    temp.push_back(A[index]);
    dfs(index, nowK + 1, sum + A[index], sumSqu + A[index] * A[index]);
    temp.pop_back();
    dfs(index + 1, nowK, sum, sumSqu);
}

int main() {
    dfs(0, 0, 0, 0);
    printf("maxSumSqu: %d\n", maxSumSqu);
    for(int i : ans) {
        printf("%d ", i);
    }
    return 0;
}