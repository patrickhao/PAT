#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

bool cmp(long long a, long long b) {
    return a > b;
}

long long arr[100010], brr[100010];

int main() {
    freopen("./sample_in/1037.txt", "r", stdin);
    int nc, np;
    int w1 = 0, w2 = 0;
    scanf("%d", &nc);
    for (int i = 0; i < nc; i++) {
        scanf("%lld", arr + i);
        if (arr[i] < 0) {
            w1++;
        }
    }
    scanf("%d", &np);
    for (int i = 0; i < np; i++) {
        scanf("%lld", brr + i);
        if (brr[i] < 0) {
            w2++;
        }
        
    }
    sort(arr, arr + nc, cmp);
    sort(brr, brr + np, cmp);
    
    long long ans = 0;
    int i = 0, j = 0;
    while (i < nc - w1 && j < np - w2) {
        ans = ans + arr[i] * brr[j];
        i++;
        j++;
    }
    i = nc - 1;
    j = np - 1;
    while (i >= nc - w1 && j >= np - w2) {
        ans = ans + arr[i] * brr[j];
        i--;
        j--;
    }
    printf("%lld", ans);

    return 0;
}