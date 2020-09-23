#include <cstdio>

void bsOut(int m, char s) {
    if(m > 0) {
        for(int i = 0; i < m; i++) {
            putchar(s);
        }
    }
}

int main() {
    freopen("./sample_in/1006.txt", "r", stdin);
    int b, s, g, temp;
    scanf("%d", &temp);
    b = temp / 100;
    s = (temp - b * 100) / 10;
    g = temp - b * 100 - s * 10; 
    //g = temp % 10;
    bsOut(b, 'B');
    bsOut(s, 'S');
    if(g > 0) {
        for(int i = 1 ; i <= g; i++) {
            printf("%d", i);
        }
    }
    return 0;
}