#include <cstdio>
void reverse(int m, int n) {
    if(m / n > 0) {
        reverse(m / n, n);
    }
    printf("%d", m % n);
}

int main() {
    freopen("./sample_in/1022.txt", "r", stdin);
    unsigned int a, b, c, d;
    scanf("%d %d %d", &a, &b, &d);
    c = a + b;
    reverse(c, d);
    return 0;
}