#include <cstdio>

const int maxn = 1000001;
int index = 1, prime[maxn] = {0}, p[maxn] = {0};

void findPrime(int n) {
    for(int i = 2; i < maxn; i++) {
        if(!p[i]) {
            prime[index++] = i;
            if(index > n) {
                break;
            }
            for(int j = i + i; j < maxn; j += i) {
                p[j] = 1;
            }
        }
    }
}

int main() {
    freopen("./sample_in/1013.txt", "r", stdin);
    int m, n, index1, index2, num = 1;
    scanf("%d %d", &m, &n);
    findPrime(n);
    for(int i = m; i <= n; i++) {
        printf("%d", prime[i]);
        if(num++ % 10 != 0 && i < n) {
            printf(" ");
        }
        else {
            printf("\n");
        }
    }

    return 0;
}