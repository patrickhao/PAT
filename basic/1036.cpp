#include <cstdio>

int main() {
    freopen("./sample_in/1036.txt", "r", stdin);
    int lengthX, lengthY;
    char sChar;
    scanf("%d %c", &lengthX, &sChar);
    if(lengthX % 2 == 0) {
        lengthY = lengthX / 2;
    }
    else {
        lengthY = lengthX / 2 + 1;
    }
    for(int i = 0; i < lengthX; i++) {
        putchar(sChar);
    }
    putchar('\n');
    for(int i = 0; i < lengthY - 2; i ++) {
        putchar(sChar);
        for(int j = 0; j < lengthX - 2; j ++) {
            putchar(' ');
        }
        putchar(sChar);
        putchar('\n');
    }
    for(int i = 0; i < lengthX; i++) {
        putchar(sChar);
    }
    return 0;
}