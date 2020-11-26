#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long LL;
const int maxn = 100010;
LL arr[maxn];
int n;

int main() {
    freopen("./sample_in/1113.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", arr + i);
    }
    sort(arr, arr + n);
    LL s1 = 0, s2 = 0;
    for (int i = 0; i < n / 2; i++) {
        s1 += arr[i];
    }
    for (int i = n / 2; i < n; i++) {
        s2 += arr[i];
    }
    if (n % 2 == 0) {
        printf("0 ");
    } else {
        printf("1 ");
    }
    printf("%lld", s2 - s1);

    return 0;
}