#include <cstdio>

//最后为确定的位数的数字可以将数字单独提出来拼接到id上
//将字符串映射为整数,全为大写，为26进制，A-Z为0-25，再将26进制转换为十进制
int hashFunc1(char s[], int len) {
    int id = 0;
    for(int i = 0; i < len; i++) {
        id = id * 26 + s[i] - 'A';
    }
    return id;
}

//将字符串映射为整数,含大小写，2*26为52进制，A-Z为0-25，a-z为26-51再将52进制转换为十进制
int hashFunc2(char s[], int len) {
    int id = 0;
    for(int i = 0; i < len; i++) {
        if(s[i] >= 'A' && s[i] <= 'Z') {
            id = id * 56 + s[i] - 'A';
        }
        else {
            id = id * 56 + s[i] - 'a' + 26;
        }
    }
    return id;
}

int main() {
    char s1[] = "abcdefg";
    char s2[] = "abcDefG";
    printf("%d\n", hashFunc1(s1, 7));
    printf("%d\n", hashFunc2(s2, 7));
    return 0;
}