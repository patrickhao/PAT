#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 50;
const int MAXV = 150;
int w[MAXN] = {0}, dp[MAXV] = {0};
bool choice[MAXN][MAXV] = {false};
bool flag[MAXN] = {false};

bool cmp(int a, int b) { return a > b; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> w[i];
    sort(w + 1, w + n + 1, cmp);

    for (int i = 1; i <= n; i++) {
        for (int v = m; v >= w[i]; v--) {
            if (dp[v - w[i]] + w[i] >= dp[v]) {
                dp[v] = dp[v - w[i]] + w[i];
                choice[i][v] = true;
            } else {
                choice[i][v] = false;
            }
        }
    }

    if (dp[m] != m) cout << "No Solution" << endl;
    else {
        int k = n, cnt = 0, v = m;
        while (k >= 0) {
            if (choice[k][v] == 1) {
                flag[k] = true;
                v -= w[k];
                cnt++;
            } else flag[k] = false;
            k--;
        }
        for (int i = n; i >= 1; i--) {
            if (flag[i]) {
                cout << w[i];
                cout << (cnt-- > 1 ? " " : "\n");
            }
        }
    }
    return 0;
}