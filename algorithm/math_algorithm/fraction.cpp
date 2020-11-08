#include <cstdio>
#include <cmath>

struct fraction{
    long long up, down;
    fraction(long long _up, long long _down) :  up(_up), down(_down) {}
    fraction() {};
};

int gcd(int m, int n) {
    return n ? gcd(n, m % n) : m;
}

//化简
fraction reduction(fraction ans) {
    if(ans.down < 0) {
        ans.up *= -1;
        ans.down *= -1;
    }
    if(ans.up == 0) {
        ans.down = 1;
    }
    else {
        int d = gcd(ans.up, ans.down);
        ans.up /= d;
        ans.down /= d;
    }
    return ans;
}

//加法
fraction add(fraction f1, fraction f2) {
    fraction ans;
    ans.up = f1.up * f2.down + f2.up * f1.down;
    ans.down = f1.down * f2.down;
    return reduction(ans);
}

fraction minu(fraction f1, fraction f2) {
    fraction ans;
    ans.up = f1.up * f2.down - f2.up * f1.down;
    ans.down = f1.down * f2.down;
    return reduction(ans);
}

fraction multi(fraction f1, fraction f2) {
    fraction ans;
    ans.up = f1.up * f2.up;
    ans.down = f1.down * f2.down;
    return reduction(ans);
}

fraction divide(fraction f1, fraction f2) {
    fraction ans;
    ans.up = f1.up * f2.down;
    ans.down = f1.down * f2.up;
    return reduction(ans);
}

void showResult(fraction f) {
    f = reduction(f);
    if(f.down == 1) {
        printf("%lld", f.up);
    }
    else if(abs(f.up) > f.down) {
        printf("%lld %lld/%lld", f.up / f.down, abs(f.up) % f.down, f.down);
    }
    else {
        printf("%lld/%lld", f.up, f.down);
    }
}

int main() {
    fraction a = fraction(3, 5);
    fraction b = fraction(6, 7);
    showResult(add(a, b));
    return 0;
}