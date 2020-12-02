#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
struct bign {
    int num[1010];
    int len;

    bign() {
        fill(num, num + 1010, 0);
        len = 0;
    }
};

bool judge(bign a) {
    int len = a.len;
    for (int i = 0; i < len / 2; i++) {
        if (a.num[i] != a.num[len - 1 - i]) {
            return false;
        }
    }
    return true;
}

bign convert(char s[]) {
    bign ans;
    for (int i = 0; i < strlen(s); i++) {
        ans.num[ans.len++] = s[strlen(s) - i - 1] - '0';
    }
    return ans;
}

bign add(bign a1, bign a2) {
    bign ans;
    int carry = 0;
    for (int i = 0; i < a1.len || i < a2.len; i++) {
        carry = carry + a1.num[i] + a2.num[i];
        ans.num[ans.len++] = carry % 10;
        carry /= 10;
    }
    if (carry != 0) {
        ans.num[ans.len++] = carry;
    }
    return ans;
}

void showBign(bign a) {
    for (int i = a.len - 1; i >= 0; i--) {
        printf("%d", a.num[i]);
    }
}

int main() {
    freopen("./sample_in/1136.txt", "r", stdin);
    int t = 0;
    char s1[1000], s2[1000];
    bool flag = false;
    scanf("%s", s1);
    bign a1 = convert(s1), a2, temp;
    if (judge(a1)) {
        showBign(a1);
        printf(" is a palindromic number.\n");
        return 0;
    }
    while (t < 10) {
        a2 = a1;
        reverse(a2.num, a2.num + a2.len); 
        temp = add(a1, a2);
        showBign(a1);
        printf(" + ");
        showBign(a2);
        printf(" = ");
        showBign(temp);
        printf("\n");
        if (judge(temp)) {
            flag = true;
            break;
        }
        a1 = temp;
        t++;
    }
    if (flag) {
        showBign(temp);
        printf(" is a palindromic number.\n");
    } else {
        printf("Not found in 10 iterations.\n");
    }
    return 0;
}