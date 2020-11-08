#include <cstdio>

//末尾空格不好处理，在下一个字符前方输出空格
int main() {
    freopen("./sample_in/1082.txt", "r", stdin);
    char out1[10][5] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    char out2[5][5] = {"Shi", "Bai", "Qian", "Wan", "Yi"};
    char c, input[11] = {0};
    int index = 0, zeroTag = 0, firstTag = 1, printTag = 0;
    while((c = getchar()) != '\n') {
        if(c == '-') {
            printf("Fu ");
        }
        else {
            input[index++] = c; 
        }
    }
    for(int i = 0; i < index / 2; i++) {
        char temp = input[0 + i];
        input[0 + i] = input[index - 1 - i];
        input[index - 1 - i] = temp;
    }
    for(int i = index - 1; i >= 0; i--) {
        if(input[i] != '0') {
            if(zeroTag) {
                printf(" ling");
                zeroTag = 0;
            }
            if(firstTag) {
                printf("%s", out1[input[i] - '0']);
                firstTag = 0;
                printTag = 1;
            }
            else {
                printf(" %s", out1[input[i] - '0']);
                printTag = 1;
            }
            if(i != 0) {
                if(i % 4 == 0) {
                    if(printTag) {
                        printf(" %s", out2[i / 4 + 2]);
                        printTag = 0;
                    }
                }
                else {
                    printf(" %s", out2[i % 4 - 1]);
                }
            }
        }
        else {
            zeroTag = 1;
            if(i % 4 == 0 && i != 0) {
                if(printTag) {
                    printf(" %s", out2[i / 4 + 2]);
                    printTag = 0;
                }
            }
        }
    }
    if(input[0] == '0' && index == 1) {
        printf("ling");
    }

    return 0;
}