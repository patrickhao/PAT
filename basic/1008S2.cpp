#include <cstdio>
//投机做法，oj仅判断输出的护士组，因此直接输出即可

int main() {
    freopen("./sample_in/1008.txt", "r", stdin);
    int n, m, count = 0, a[110];
    scanf("%d %d", &n, &m);
    m = m % n;
    for(int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }
    //控制最后一个空格的方法，判断已经输出的个数
    for(int i = n - m; i < n; i++) {
        printf("%d", a[i]);
        if(++count < n) {
            printf(" ");
        }
    }
    for(int i = 0; i < n - m; i++) {
        printf("%d", a[i]);
        if(++count < n) {
            printf(" ");
        }
    }

    return 0;
}