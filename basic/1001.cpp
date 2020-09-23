#include <cstdio>
#include <cstdlib>

int ispositive(int a) {
    return a % 2;
}

int main() {
    freopen("./sample_in/1001.txt", "r", stdin);
    int n, count;
    count = 0;
    scanf("%d", &n);
    while (n != 1) {
        if (ispositive(n)) { //奇数
            n = (3 * n + 1) / 2;
            count++;
        } 
        else {
            n = n / 2;
            count++;
        }
    }
    printf("%d", count);

    return 0;
}