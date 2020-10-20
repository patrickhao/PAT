#include <cstdio>

int main() {
    freopen("./sample_in/1019.txt", "r", stdin);
    int a[100] = {0}, n, b, index = 0, flag = 1;
    scanf("%d %d", &n, &b);
    while(n) {
        a[index++] = n % b;
        n /= b;
    }
    for(int i = 0; i < index / 2; i++) {
        if(a[i] != a[index - 1 - i]) {
            flag = 0;
            break;
        }
    }
    if(flag) {
        printf("Yes\n");
    }
    else {
        printf("No\n");
    }
    //进制转换，最后的输出应该倒序，a[0]是个位
    for(int i = index - 1; i > 0; i--) {
        printf("%d ", a[i]);
    }
    printf("%d", a[0]);

    return 0;
}