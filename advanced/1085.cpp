#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n, p, i;
int arr[100010];

int binarySearch(int left, int right) {
    int mid;
    while (left < right) {
        mid = (left + right) / 2;
        if (arr[mid] <= (long long)arr[i] * p) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
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
            r = binarySearch(i + 1, n - 1);
        }
        ans = max(ans, r - i);
    }
    printf("%d", ans);
    return 0;
}