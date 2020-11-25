#include <cstdio>

using namespace std;
const int maxn = 110;
typedef long long LL;

struct fraction {
    LL up, down;
} fra;

LL abs(LL n) {
    return n < 0 ? -1 * n : n;
}

LL gcd(LL a, LL b) {
    return b ? gcd(b, a % b) : a;
}

void reduction(fraction &f) {
    if (f.down < 0) {
        f.up = -1 * f.up;
        f.down = -1 * f.down;
    }
    if (f.up == 0) {
        f.down = 1;
    }
    LL g = gcd(abs(f.up), abs(f.down));
    f.up /= g;
    f.down /= g; 
}

fraction add(fraction f1, fraction f2) {
    fraction ans;
    ans.up = f1.up * f2.down + f2.up * f1.down;
    ans.down = f1.down * f2.down;
    reduction(ans);
    return ans;
}

void show(fraction f) {
    if (f.down == 1) {
        printf("%lld", f.up);
    } else if (f.up >= f.down) {
        LL a = abs(f.up);
        printf("%lld %lld/%lld", f.up / f.down, a % f.down, f.down);
    } else {
        printf("%lld/%lld", f.up, f.down);
    }
}

int main() {
    freopen("./sample_in/1081.txt", "r", stdin);
    int n;
    fraction ans;
    ans.up = 0;
    ans.down = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld/%lld", &fra.up, &fra.down);
        ans = add(ans, fra);
    }
    show(ans);

    return 0;
}