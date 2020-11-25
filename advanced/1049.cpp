#include <cstdio>
#include <cmath>

using namespace std;
typedef long long LL;

int oneNum(LL n) {
    int ans = 0;
    while (n) {
        int temp = n % 10;
        if (temp == 1) {
            ans++;
        }
        n /= 10;
    }
    return ans;
}

int main() {
    freopen("./sample_in/1049.txt", "r", stdin);
    LL num;
    scanf("%lld", &num);
    int ans = 0;
    for (LL i = 1; i <= num; i++) {
        ans += oneNum(i);
    }
    printf("%d\n", ans);

    return 0;
}