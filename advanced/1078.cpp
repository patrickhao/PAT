#include <cstdio>
#include <algorithm>

using namespace std;
const int maxn = 100010;

int ind = 0, prime[maxn];
bool hashTable[maxn] = {false};
bool flag[maxn] = {false};

void findPrime() {
    for (int i = 2; i < maxn; i++) {
        if (!flag[i]) {
            prime[ind++] = i;
            for (int j = i + i; j < maxn; j += i) {
                flag[j] = true;
            }
        } 
    }
}

int main() {
    freopen("./sample_in/1078.txt", "r", stdin);
    findPrime();
    int m, n;
    scanf("%d %d", &m, &n);
    for (int i = 0; i < maxn; i++) {
        if (prime[i] >= m) {
            m = prime[i];
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        if (!hashTable[temp % m]) {
            hashTable[temp % m] = true;
            printf("%d", temp % m);
        } else {
            bool t = true;
            for (int j = 1; j < m; j++) {
                if (!hashTable[(temp + j * j) % m]) {
                    printf("%d", (temp + j * j) % m);
                    hashTable[(temp + j * j) % m] = true;
                    t = false;
                    break;
                }
            }
            if (t) {
                printf("-");
            }
        }
        if (i < n - 1) {
            printf(" ");
        }
    }

    return 0;
}