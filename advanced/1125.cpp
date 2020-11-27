#include <cstdio>
#include <algorithm>

using namespace std;
double arr[10010];

int main() {
    freopen("./sample_in/1125.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", arr + i);
    }
    sort(arr, arr + n);
    for (int i = 0; i < n - 1; i++) {
        arr[i + 1] = arr[i] / 2.0 + arr[i + 1] / 2.0;
    }
    printf("%d", (int)arr[n - 1]);

    return 0;
}