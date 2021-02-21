#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 +10;

struct bign {
    int d[MAXN];
    int len;

    bign() {
        fill(d, d + MAXN, 0);
        len = 0;
    }
};

bign tranform(string s) {
    bign ret;
    ret.len = s.length();
    for (int i = s.length() - 1; i >= 0; i--) {
        ret.d[s.length() - 1 - i] = s[i] - '0';
    }
    return ret;
}

bign divide(bign a, int b, int& r) {
    bign ans;
    ans.len = a.len;
    for (int i = a.len - 1; i >= 0; i--) {
        r = r * 10 + a.d[i];
        if (r < b) ans.d[i] = 0;
        else {
            ans.d[i] = r / b;
            r = r % b;
        }
    }
    while (ans.len - 1 >= 1 && ans.d[ans.len - 1] == 0) ans.len--;
    return ans;
}

void printBign(bign a) {
    for (int i = a.len - 1; i >= 0; i--) cout << a.d[i];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string s;
    int n;
    cin >> s >> n;
    int r = 0;
    bign a = tranform(s);
    bign ans = divide(a, n, r);
    printBign(ans);
    cout << " " << r << endl;
    return 0;
}