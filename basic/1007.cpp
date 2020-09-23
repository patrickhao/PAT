#include <cstdio>

bool isPrime(int m) {
    //题中卡了时间复杂度，必须优化i的范围
    for(int i = 2; i * i <= m; i++) {
        if(m % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    freopen("./sample_in/1007.txt", "r", stdin);
    int preP = 1, p = 0, count = 0, n;
    scanf("%d", &n);
    for(int i = 2; i <= n; i++) {
        if(isPrime(i)) {
            if(i - preP == 2) {
                count++;
            }
        preP = i;
        }
    }
    printf("%d", count);
    return 0;
}