#include <cstdio>
#include <cstring>

//正着不好处理就将字符串反转
void reverse(char s[], int len) {
    char temp;
    for(int i = 0; i < len / 2; i++) {
        temp = s[0 + i];
        s[0 + i] = s[len - 1 - i];
        s[len - 1 - i] = temp;
    }
}

int main() {
    freopen("./sample_in/1077.txt", "r", stdin);
    int n, len, ansIndex = 0, minlen = 300, flag = 1;
    char s[100][300] = {0};
    scanf("%d", &n);
    getchar();
    for(int i = 0; i < n; i++) {
        gets(s[i]);
        len = strlen(s[i]);
        if(len < minlen) {
            minlen = len;
        }
        reverse(s[i], len);
    }
    for(int i = 0; i < minlen; i++) {
        for(int j = 1; j < n; j++) {
            if(s[j][i] != s[0][i]) {
                flag = 0;
                break;
            }
        }
        if(flag) {
            ansIndex++;
        }
        else {
            break;
        }
    }
    if(ansIndex) {
        for(int i = ansIndex - 1; i >= 0; i--) {
            putchar(s[0][i]);
        }
    }
    else {
        printf("nai");
    }

    return 0;
}