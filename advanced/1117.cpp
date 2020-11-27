#include <cstdio>
#include <algorithm>

using namespace std;
int n, arr[100010];

bool cmp(int a, int b) {
    return a > b;
}
 
int main() {
    freopen("./sample_in/1117.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", arr + i);
    }
    sort(arr + 1, arr + 1 + n, cmp);
    int i;
    for (i = 1; i <= n; i++) {
        if (arr[i] <= i) {
            break;
        }
    }
    printf("%d", i - 1);
    return 0;
}