#include <cstdio>

using namespace std;
long long arr[1000010], brr[1000010], crr[1000010];

int main() {
    freopen("./sample_in/1029.txt", "r", stdin);
    int n1, n2;
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        scanf("%lld", arr + i);
    } 
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        scanf("%lld", brr + i);
    } 

    int index = 0, i = 0, j = 0;
    while (i < n1 && j < n2) {
        if (arr[i] <= brr[j]) {
            crr[index++] = arr[i++];
        } else {
            crr[index++] = brr[j++];
        }
    }
    while (i < n1) {
        crr[index++] = arr[i++];
    }
    while (j < n2) {
        crr[index++] = brr[j++];
    }
    printf("%lld\n", crr[(index - 1) / 2]);

    return 0;
}