#include <cstdio>
#include <cstdlib>

int main() {
    freopen("./sample_in/1001.txt", "r", stdin);
    int a, b, c, index = 0;
    int* num = (int*)malloc(10000000 * sizeof(int));
    scanf("%d %d", &a, &b);
    c = a + b;
    if(c < 0) {
        printf("-");
        c = -c;
    }
    while(c) {
        num[index++] = c % 10;
        c /= 10;
    }
    if(index == 0) {
        index = 1;
    }
    for(int i = index - 1; i >= 0; i--) {
        if(i % 3 == 0 && i != 0) {
            printf("%d,", num[i]);
        }
        else {
            printf("%d", num[i]);
        }
    }
    return 0; 
}