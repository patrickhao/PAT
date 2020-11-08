#include <cstdio>

long long binaryPow1(long long a, long long b, long long m) {
    if(b == 0) {
        return 1; 
    }
    if(b % 2 == 1) {
        return a * binaryPow1(a, b - 1, m) % m;
    }
    else {
        long long temp = binaryPow1(a, b / 2, m);
        return temp * temp % m;
    }
}

long long binaryPow2(long long a, long long b, long long m) {
    long long ans = 1;
    while(b) {
        if(b & 1) {
            ans = ans * a % m;
        }
        a = a * a % m;
        b >>= 1;
    }
    return ans;
}

int main() {
    printf("%lld\n", binaryPow1(233333, 23333333333333, 23));
    printf("%lld\n", binaryPow2(233333, 23333333333333, 23));
    return 0;
}