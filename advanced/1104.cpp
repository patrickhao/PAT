#include <cstdio>

using namespace std;
const int maxn = 100010;

int main() {
    freopen("./sample_in/1104.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    long long ans = 0;
    double temp;
    for (int i = 0; i < n; i++) {
        scanf("%lf", &temp);
        ans += (long long)(1000 * temp) * (i + 1) * (n - i);
    }
    printf("%0.2f\n", ans / 1000.0);

    return 0;
}