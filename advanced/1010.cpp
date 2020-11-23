#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long LL;
LL inf = (1LL << 63) - 1;

char num1[12], num2[12];

LL transform(char c) {
    LL ans;
    if (isalpha(c)) {
        ans = c - 'a' + 10;
    } else {
        ans = c - '0';
    }
    return ans;
}

LL toDecimal(char num[], LL tag, LL t) {
    LL ans = 0;
    for (int i = 0; i < strlen(num); i++) {
        ans = ans * tag + transform(num[i]);
        if(ans < 0 || ans > t) {
            return -1;
        }
    }
    return ans;
}

int cmp(char num2[], LL tag, LL t) {
    LL num = toDecimal(num2, tag, t);
    if (num < 1) {
        return 1;
    }
    if (t > num) {
        return -1;
    } else if (t == num) {
        return 0;
    } else {
        return 1;
    }
    
}

LL binarySearch(char num2[], LL left, LL right, LL n1) {
    LL mid;
    while (left <= right) {
        mid = left + (right - left) / 2;
        int flag = cmp(num2, mid, n1);
        if (flag == 0) {
            return mid;
        } else if (flag > 0) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

int main() {
    freopen("./sample_in/1010.txt", "r", stdin);
    int tag, d1;
    scanf("%s %s", num1, num2);
    scanf("%d %d", &tag, &d1);
    if (tag == 2) {
        swap(num1, num2);
    }
    LL n1 = 0;
    n1 = toDecimal(num1, d1, inf);

    //find bound
    LL left = -1;
    for (int i = 0; i < strlen(num2); i++) {
        if (transform(num2[i]) > left) {
            left = transform(num2[i]);
        }
    }
    LL right = max(left, n1) + 1;
    LL d2 = binarySearch(num2, left + 1, right, n1);
    if (d2 == -1) {
        printf("Impossible\n");
    } else {
        printf("%lld\n", d2);
    }

    return 0;
}