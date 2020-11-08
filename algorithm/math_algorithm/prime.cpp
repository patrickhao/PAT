#include <cstdio>
#include <cmath>

const int maxn = 101;
int indexP = 0, prime[maxn] = {0}, p[maxn] = {0};

bool isPrime(int n) {
    if(n <= 1) {
        return false;
    }
    int sqr = (int)sqrt(1.0 * n);
    for(int i = 2; i <= sqr; i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

//p[i]:1素数,0合数
void findPrime1() {
    for(int i = 0; i < maxn; i++) {
        if(isPrime(i)) {
            prime[indexP++] = i;
            p[i] = 1;
        }
    }
}

//p[i]:1合数,0素数
void findPrime2() {
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
    findPrime1();
    for(int i = 0; i < indexP; i++) {
        printf("%d ", prime[i]);
    }
    return 0;
}