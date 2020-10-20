#include <cstdio>
//问题一：进制转换循环从个位往大算，所以输出应该倒序
//问题二：以为10的9次方的数要开大数组，因此选择麻烦的方法，但是10的9次方一共才9位，就算转成二进制，100个int的数组绰绰有余，2的100次方是很大的数

int func(int m, int n, int t) {
    if(t == 0) {
        return m;
    }
    else {
        for(int i = 0; i < t; i++) {
            m /= n;
        }
    }
    return m;
}

int main() {
    freopen("./sample_in/1019.txt", "r", stdin);
    int n, b, temp, len = 1, flag = 1;
    scanf("%d%d", &n, &b);
    temp = b;
    while(n / temp) {
        temp *= b;
        len++;
    }
    for(int i = 0; i < len / 2; i++) {
        if(func(n, b, i) % b != func(n, b, i) % b) {
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
    for(int i = len - 1; i > 0; i--) {
        printf("%d ", func(n, b, i) % b);
    }
    printf("%d", func(n, b, 0) % b);

    return 0;
}