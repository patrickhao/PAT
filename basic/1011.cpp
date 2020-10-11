#include <cstdio>

int main() {
    freopen("./sample_in/1011.txt", "r", stdin);
    int num;
    scanf("%d", &num);
    for(int i = 0; i < num; i++) {
        long long a ,b ,c;
        scanf("%lld%lld%lld", &a, &b, &c);
        printf("Case #%d: ", i + 1);
        if(a + b > c) {
            printf("true\n");
        }
        else {
            printf("false\n");
        }
    }

    return 0;
}