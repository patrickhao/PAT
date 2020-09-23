#include <cstdio>

int main() {
    freopen("./sample_in/1009.txt", "r", stdin);
    char readIn[81];
    char wordTemp[81];
    char c;
    int length = 0, wordTempLength = 0, index;
    c = getchar();
    for(int i = 0; c != EOF; i ++) {
        readIn[i] = c;
        c = getchar();
        length ++;
    }
    index = length - 1;
    for(int i = index; i >= 0; i --) {
        c = readIn[i];
        if(c == ' ') {
            if(i == 0) {
                for(int j = wordTempLength - 1; j >= 0; j --) {
                    putchar(wordTemp[j]);
                    wordTemp[j] = 0;
                }
                wordTempLength = 0;
            }
            else if(readIn[i - 1] == ' ') {
                continue;
            }
            else {
                for(int j = wordTempLength - 1; j >= 0; j --) {
                    putchar(wordTemp[j]);
                    wordTemp[j] = 0;
                }
                wordTempLength = 0;
                putchar(c);
            }

        }
        else if(i == 0) {
            wordTemp[wordTempLength ++] = c;
            for(int j = wordTempLength - 1; j >= 0; j --) {
                putchar(wordTemp[j]);
                wordTemp[j] = 0;
            }
        }
        else {
            wordTemp[wordTempLength ++] = c;
        }
    }
    return 0;
}