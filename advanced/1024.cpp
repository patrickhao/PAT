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

bign change(string s) {
    bign ans;
    ans.len = s.length();
    for (int i = 0; i < s.length(); i++) {
        ans.d[i] = s[s.length() - i - 1] - '0';
    }
    return ans;
}

bign add(bign m, bign n) {
    bign ans;
    int carry = 0;
    for (int i = 0; i < m.len || i < n.len; i++) {
        int temp = m.d[i] + n.d[i] + carry;
        ans.d[ans.len++] = temp % 10;
        carry = temp / 10;
    }
    if (carry != 0) {
        ans.d[ans.len++] = carry;
    }
    return ans;
}

bign bc(bign m) {
    bign ans = m;
    reverse(ans.d, ans.d + m.len);
    return ans; 
}

bool judge(bign m) {
    for (int i = 0; i < m.len / 2; i++) {
        if (m.d[i] != m.d[m.len - 1 - i]) {
            return false;
        }
    }
    return true;
}

int main() {
    //freopen("./sample_in/1024.txt", "r", stdin);
    string num;
    int k;
    cin >> num >> k;
    bign m = change(num);
    bign b;
    int i;
    if (judge(m)) {
        for (int i = m.len - 1; i >= 0; i--) {
            printf("%d", m.d[i]);
        }
        printf("\n0\n");
        return 0;
    }
    for (i = 1; i <= k; i++) {
        b = add(m, bc(m));
        if (judge(b)) {
            break;
        }
        m = b;
    }
    for (int i = b.len - 1; i >= 0; i--) {
        printf("%d", b.d[i]);
    }
    if (i <= k) {
        printf("\n%d\n", i);
    } else {
        printf("\n%d\n", k);
    }

    return 0;
}