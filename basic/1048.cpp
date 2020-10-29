#include <cstdio>

//加密用的A要用完
int main() {
    freopen("./sample_in/1048.txt", "r", stdin);
    char outChar[3] = {'J', 'Q', 'K'};
    char c, a[110] = {0}, b[110] = {0}, out[110] = {0};
    int temp, tempA, tempB, indexA = 0, indexB = 0, indexOut = 0, flag = 1;
    while((c = getchar()) != ' ') {
        a[indexA++] = c;
    }
    while((c = getchar()) != '\n') {
        b[indexB++] = c;
    }
    while(indexA > 0 || indexB > 0) {
        indexA--;
        indexB--;
        tempA = indexA < 0 ? 0 : a[indexA] - '0';
        tempB = indexB < 0 ? 0 : b[indexB] - '0';
        if(flag) {
            temp = tempA + tempB;
            temp %= 13;
            if(temp < 10) {
                out[indexOut++] = '0' + temp;
            }
            else {
                out[indexOut++] = outChar[temp - 10];
            }
        }
        else {
            temp =tempB - tempA;
            if(temp < 0) {
                temp += 10;
            }
            out[indexOut++] = temp + '0';
        }
        flag = (flag + 1) % 2;
    }
    for(int i = indexOut - 1; i >= 0; i--) {
        putchar(out[i]);
    }

    return 0;
}