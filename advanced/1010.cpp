#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>

using namespace std;

int transform(char c) {
    if (isalpha(c)) {
        return c - 'a' + 10;
    } else {
        return c - '0';
    }
}

long long toDecimal(char num[], int tag) {
    long long ans = 0;
    for (int i = 0; i < strlen(num); i++) {
        ans = ans * tag + transform(num[i]);
    }
    return ans;
}

int main() {
    freopen("./sample_in/1010.txt", "r", stdin);
    char num1[12], num2[12];
    int tag, d1;
    scanf("%s %s", num1, num2);
    scanf("%d %d", &tag, &d1);
    if (tag == 2) {
        swap(num1, num2);
    }
    long long n1 = 0;
    for (int i = 0; i < strlen(num1); i++) {
        n1 = n1 * d1 + transform(num1[i]);
    }

    //find bound
    int right = 0;
    for (int i = 0; i < strlen(num2); i++) {
        if (transform(num2[i]) > right) {
            right = transform(num2[i]);
        }
    }
    
    int d2 = -1;
    for (int i = 2; i < right + 2; i++) {
        if (toDecimal(num2, i) == n1) {
            d2 = i;
            break;
        }
    }
    if (d2 == -1) {
        printf("Impossible\n");
    } else {
        printf("%d\n", d2);
    }

    return 0;
}