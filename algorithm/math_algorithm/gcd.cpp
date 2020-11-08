#include <cstdio>

int gcd(int m, int n) {
    return n ? gcd(n, m % n) : m;
}

int main() {
    printf("%d", gcd(2, 3));

    return 0;
}