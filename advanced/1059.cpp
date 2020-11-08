#include <cstdio>

typedef struct {
    int x, cnt;
} factor;

const int maxn = 10001;
int indexP = 0, prime[maxn] = {0}, p[maxn] = {0};

void findPrime() {
    for(int i = 2; i < maxn; i++) {
        if(!p[i]) {
            prime[indexP++] = i;
            for(int j = i + i; j < maxn; j += i) {
                p[j] = 1;
            }
        }
    }
}

int main() {
    freopen("./sample_in/1059.txt", "r", stdin);
    factor f[maxn];
    long long n, bn;
    int indexN = 0;
    findPrime();
    scanf("%lld", &n);
    bn = n;
    if(n > 1) {
        for(int i = 0; i < indexP; i++) {
            if(n % prime[i] == 0) {
                f[indexN].x = prime[i];
                f[indexN].cnt = 0;
                while(n % prime[i] == 0) {
                    f[indexN].cnt++;
                    n /= prime[i];
                }
                indexN++;
            }
        }
        if(n > 1) {
            f[indexN].x = n;
            f[indexN].cnt = 1;
            indexN++;
        }
    }
    else {
        f[indexN].x = 1;
        f[indexN].cnt = 1;
        indexN++;
    }

    printf("%lld=", bn);
    for(int i = 0; i < indexN; i++) {
        printf("%d", f[i].x);
        if(f[i].cnt > 1) {
            printf("^%d", f[i].cnt);
        }
        if(i < indexN - 1) {
            printf("*");
        }
    }

    return 0;
}