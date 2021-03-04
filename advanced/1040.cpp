#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 50;
int dp[MAXN][MAXN] = {0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string s;
    getline(cin, s);
    int n = s.length(), ans = 1;
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
        if (i + 1 < n && s[i] == s[i + 1]) {
            dp[i][i + 1] = 1;
            ans = 2;
        }
    }

    for (int len = 3; len <= n; len++) {
        for (int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;
            if (s[i] == s[j] && dp[i + 1][j - 1] == 1) {
                dp[i][j] = 1;
                ans = len;
            }
        }
    }
    cout << ans << endl;
    return 0;
}