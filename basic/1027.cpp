#include <cstdio>

int printLine(int a, int b, char c) {
    int sum = 0;
    int blankNum = (a - b) / 2;
    for(int i = 0; i < blankNum; i++) {
        printf(" ");
    }
    for(int i = 0; i < b; i++) {
        printf("%c", c);
        sum++;
    }
    printf("\n");
    return sum;
}

int main() {
    freopen("./sample_in/1027.txt", "r", stdin);
    int num, sum = 0, used = 0, firstNum = 1, lineNum = 0;
    char c;
    scanf("%d %c", &num, &c);
    for(int i = 0; i < num; i++) {
       sum += 2 * i + 1;
       if(2 * sum - 1 > num) {
           lineNum = i;
           firstNum = 2 * i - 1;
           break;
       }
       else if(2 * sum - 1 == num) {
           lineNum = i + 1;
           firstNum = 2 * i + 1;
           break;
       }
    }
    for(int i = 0; i < lineNum; i++) {
       used += printLine(firstNum, firstNum - 2 * i, c); 
    }
    for(int i = 1; i < lineNum; i++) {
       used += printLine(firstNum, 2 * i + 1, c);
    }
    printf("%d", num - used);

    return 0;
}