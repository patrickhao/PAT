#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n, p, i;
int arr[100010];

int binarySearch(int left, int right, long long X) {
    if (arr[n - 1] <= X) {
        return n;
    }
    int mid, l = left, r = right;
    while (l < r) {
        mid = (l + r) / 2;
        if (!(arr[mid] <= X)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

int main() {
    freopen("./sample_in/1085.txt", "r", stdin);
    scanf("%d %d", &n, &p);
    for (int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }
    sort(arr, arr + n);

    int ans = 1;
    for (int i = 0; i < n; i++) {
        int r;
        if (arr[n - 1] <= (long long)arr[i] * p) {
            r = n;
        } else {
            r = binarySearch(i + 1, n - 1, (long long)arr[i] * p);
        }
        ans = max(ans, r - i);
    }
    printf("%d", ans);
    return 0;
}