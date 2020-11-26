#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct bign {
    int d[1000];
    int len;

    bign() {
        fill(d, d + 1000, 0);
        len = 0;
    }
};

bign change(string num1) {
    bign ans;
    ans.len = num1.length();
    for (int i = 0; i < num1.length(); i++) {
        ans.d[i] = num1[num1.length() - i - 1] - '0';
    }
    return ans;
}

bign multi(bign m, int n) {
    bign ans;
    int carry = 0;
    for (int i = 0; i < m.len; i++) {
        int temp = m.d[i] * n + carry;
        ans.d[ans.len++] = temp % 10;
        carry = temp / 10;
    }
    while (carry != 0) {
        ans.d[ans.len++] = carry % 10;
        carry /= 10;
    }
    return ans;
}


int main() {
    freopen("./sample_in/1023.txt", "r", stdin);
    string num;
    int hashTable[21] = {0};
    cin >> num;
    for (int i = 0; i < num.length(); i++) {
        hashTable[num[i] - '0']++;
    }
    bign n1 = change(num);
    bign n2 = multi(n1, 2);
    for (int i = 0; i < n2.len; i++) {
        hashTable[n2.d[i]]--;
    }
    int tag = true;
    for (int i = 0; i < n2.len; i++) {
        if (hashTable[i] != 0) {
            tag = false;
            break;
        }
    }
    if (tag) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    for (int i = n2.len - 1; i >= 0; i--) {
        printf("%d", n2.d[i]);
    }

    return 0;
}