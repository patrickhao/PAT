#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>

using namespace std;

char num1[12], num2[12];

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

int binarySearch(int left, int right, long long n1) {
    int mid;
    while (left < right) {
        mid = left + (right - left) / 2;
        if (toDecimal(num2, mid) >= n1) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int main() {
    freopen("./sample_in/1010.txt", "r", stdin);
    int tag, d1;
    scanf("%s %s", num1, num2);
    scanf("%d %d", &tag, &d1);
    if (tag == 2) {
        swap(num1, num2);
    }
    long long n1 = 0;
    n1 = toDecimal(num1, d1);

    //find bound
    int left = 0;
    for (int i = 0; i < strlen(num2); i++) {
        if (transform(num2[i]) > left) {
            left = transform(num2[i]);
        }
    }
    int d2 = binarySearch(left + 1, 1000000000, n1);
    if (toDecimal(num2, d2) != n1) {
        printf("Impossible\n");
    } else {
        printf("%d\n", d2);
    }

    return 0;
}