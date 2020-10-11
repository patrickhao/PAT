#include <cstdio>

int pNumber(int m, int n) {
    int num = 0, ans = 0;
    while(m != 0) {
        if(m % 10 == n) {
            num++;
        }
        m /= 10;
    }
    for(int i = 0; i < num; i++) {
        ans = ans * 10 + n;
    }
    return ans;
}

int main() {
    freopen("./sample_in/1016.txt", "r", stdin);
    int ans = 0, a, ad;
    for(int i = 0; i < 2; i++) {
        scanf("%d%d", &a, &ad);
        ans += pNumber(a, ad);
    }
    printf("%d", ans);
    return 0;
}