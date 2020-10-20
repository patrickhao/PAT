#include <cstdio>
#include <cstring>

int main() {
    freopen("./sample_in/1031.txt", "r", stdin);
    char input[100] = {0};
    int len, n1 = 0, n2 = 0, index = 0, allN1[80] = {0};
    scanf("%s", &input);
    len = strlen(input);
    n1 = (len + 2) / 3;
    n2 = len - n1 * 2 + 2;
    for(int i = 0; i < n1 - 1; i++) {
        printf("%c", input[i]);
        for(int i = 0; i < n2 - 2; i++) {
            printf(" ");
        }
        printf("%c\n", input[len - i - 1]);
    }
    for(int i = n1 - 1; i < n1 + n2 - 1; i++) {
        printf("%c", input[i]);
    }
    
    return 0;
}