#include <cstdio>

using namespace std;
const int INF = 1000000000;
typedef long long LL;

struct fraction {
    LL up, down;
};

LL abs(LL n) {
    return n < 0 ? -1 * n : n;
}

LL gcd(LL a, LL b) {
    return b ? gcd(b, a % b) : a;
}

void reduction(fraction &f) {
    if (f.up == 0) {
        f.down = 1;
    } else if (f.down < 0) {
        f.up *= -1;
        f.down *= -1;
    }
    LL g = gcd(abs(f.up), f.down);
    f.up /= g;
    f.down /= g;
}

fraction sum(fraction f1, fraction f2) {
    fraction ans;
    ans.up = f1.up * f2.down + f2.up * f1.down;
    ans.down = f1.down * f2.down;
    reduction(ans);
    return ans;
}

fraction diff(fraction f1, fraction f2) {
    fraction ans;
    ans.up = f1.up * f2.down - f2.up * f1.down;
    ans.down = f1.down * f2.down;
    reduction(ans);
    return ans;
}

fraction prod(fraction f1, fraction f2) {
    fraction ans;
    ans.up = f1.up * f2.up;
    ans.down = f1.down * f2.down;
    reduction(ans);
    return ans;
}

fraction quot(fraction f1, fraction f2) {
    fraction ans;
    ans.up = f1.up * f2.down;
    ans.down = f1.down * f2.up;
    if (ans.down == 0) {
        ans.up = INF;
        ans.down = 1;
    }
    reduction(ans);
    return ans;
}

void show(fraction f) {
    if (f.up == INF) {
        printf("Inf");
        return;
    }
    if (f.up < 0) {
        printf("(");
    }
    if (f.down == 1) {
        printf("%lld", f.up);
    } else if (abs(f.up) >= f.down) {
        LL a = abs(f.up);
        printf("%lld %lld/%lld", f.up / f.down, a % f.down, f.down);
    } else {
        printf("%lld/%lld", f.up, f.down);
    }
    if (f.up < 0) {
        printf(")");
    }
}

int main() {
    freopen("./sample_in/1088.txt", "r", stdin);
    fraction f1, f2, ans;
    scanf("%lld/%lld %lld/%lld", &f1.up, &f1.down, &f2.up, &f2.down);
    reduction(f1);
    reduction(f2);
    show(f1);
    printf(" + ");
    show(f2);
    ans = sum(f1, f2);
    printf(" = ");
    show(ans);
    printf("\n");
    show(f1);
    printf(" - ");
    show(f2);
    ans = diff(f1, f2);
    printf(" = ");
    show(ans);
    printf("\n");
    show(f1);
    printf(" * ");
    show(f2);
    ans = prod(f1, f2);
    printf(" = ");
    show(ans);
    printf("\n");
    show(f1);
    printf(" / ");
    show(f2);
    ans = quot(f1, f2);
    printf(" = ");
    show(ans);
    printf("\n");
    return 0;
}