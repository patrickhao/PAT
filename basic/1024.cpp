#include <cstdio>

void putPart1(char c[], int len) {
    for(int i = 0; i < len; i++) {
        putchar(c[i]);
    }
}

int main() {
    freopen("sample_in/1024.txt", "r", stdin);
    char c, a1, a2, part1[10000] = {0};
    int e, index = 0;
    a1 = getchar();
    if(a1 == '-') {
        putchar(a1);
    }
    while((c = getchar()) != 'E') {
        if(c != '.')  {
            part1[index++] = c;
        }
    }
    a2 = getchar();
    scanf("%d", &e);
    if(a2 == '+') {
        if(index > e) {
            for(int i = 0; i < index; i++) {
                putchar(part1[i]);
                if(i == e && i != index - 1) {
                    putchar('.');
                }
            }
        }
        else {
            putPart1(part1, index);
            for(int i = 0; i <= e - index; i++) {
                putchar('0');
            }
        }
    }
    else {
        printf("0.");
        for(int i = 0; i < e - 1; i++) {
            printf("0");
        }
        putPart1(part1, index);
    }
    return 0;
}