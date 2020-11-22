#include <cstdio>

int main() {
    freopen("./sample_in/1008.txt", "r", stdin);
    int cur = 0, n, ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int call;
        scanf("%d", &call);
        ans += 5;
        if (call > cur) {
            ans = ans + (call - cur) * 6;
        } else if (call < cur) {
            ans = ans + (cur - call) * 4;
        }
        cur = call;
    }
    printf("%d", ans);
    return 0;
}