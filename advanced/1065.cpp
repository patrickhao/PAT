#include <cstdio>

int main() {
    freopen("./sample_in/1065.txt", "r", stdin);
    int num, flag = 0;
    long long a, b, c, ans;
    scanf("%d", &num);
    for(int i = 0; i < num; i++) {
        scanf("%lld%lld%lld", &a, &b, &c);
        flag = 0;
        //a+b必须存在long long中才能比较，否则会造成后两组数据错误
        ans = a + b;
        if((a > 0 && b > 0 && ans < 0) || a + b > c) {
            flag = 1;
        }
        if(a < 0 && b < 0 && ans >= 0) {
            flag = 0;
        }
        if(flag) {
            printf("Case #%d: true\n", i + 1);
        }
        else {
            printf("Case #%d: false\n", i + 1);
        }
    }

    return 0;
}