#include <cstdio>
#include <cmath>

using namespace std;
typedef long long LL;

int main() {
    freopen("./sample_in/1096.txt", "r", stdin);
    LL num;
    scanf("%lld", &num);
    int ansLen = 0, firstElem = 0;
    for (int i = 2; i <= sqrt(num); i++) {
        int temp = 1, j = i;
        while (temp <= num) {
            temp = temp * j;
            if (num % temp != 0) {
                break;
            }
            if (j - i + 1 > ansLen) {
                ansLen = j - i + 1;
                firstElem = i;
            }
            j++;
        }
    }
    if (ansLen == 0) {
        printf("1\n");
        printf("%lld", num);
    } else {
        printf("%d\n", ansLen);
        for (int i = 0; i < ansLen; i++) {
            printf("%d", firstElem++);
            if (i < ansLen - 1) {
                printf("*");
            }
        }
    }

    return 0;
}
