#include <cstdio>
#include <cmath>

int getlen(int n) {
    int len = 1;
    while (n / 10 != 0) {
        len++;
        n = n / 10;
    }
    return len;
}

int main() {
    freopen("./sample_in/1002.txt", "r", stdin);
    int n, sum;
    sum = 0;
    while ((n = getchar()) != '\n') {
    n = (n - 48);
    sum += n;
    }
    int length = getlen(sum);
    char han [10][5] = {
    "ling",
    "yi",
    "er",
    "san",
    "si",
    "wu",
    "liu",
    "qi",
    "ba",
    "jiu"
    };

    int reverse_sum = 0;
    for(int i=0; i < length; i++) {
        int j = sum % 10;
        sum = sum / 10;
        reverse_sum += j * pow(10, length-i-1);
    }

    int last;
    for(int i = 0; i < length - 1; i++) {
        last = reverse_sum % 10;
        reverse_sum = reverse_sum / 10;
        printf("%s ", han[last]);
    }
    printf("%s", han[reverse_sum]);

    return 0;
}