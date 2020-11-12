#include <cstdio>
#include <vector>

using namespace std;

const int maxn = 4;
int n = 4, k = 2, x = 6, maxSumSqu = -1, A[maxn] = {2, 3, 3, 4};
vector<int> temp, ans;

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
    dfs(index + 1, nowK + 1, sum + A[index], sumSqu + A[index] * A[index]);
    temp.pop_back();
    dfs(index + 1, nowK, sum, sumSqu);
}

int main() {
    dfs(0, 0, 0, 0);
    printf("%d", maxSumSqu);
    return 0;
}