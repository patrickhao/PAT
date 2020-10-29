#include <cstdio>

int main() {
    freopen("./sample_in/1005.txt", "r", stdin);
    char c;
    int sum = 0, index = 0, num[1000] = {0};
    char dict[10][6] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    while((c = getchar()) != '\n') {
        sum += (c - '0');
    }
    while(sum) {
        num[index++] = sum % 10;
        sum /= 10;
    }
    for(int i = index - 1; i > 0; i--) {
        printf("%s ", dict[num[i]]);
    }
    printf("%s", dict[num[0]]);

    return 0;
}