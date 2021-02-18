#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int x; cin >> x;
    int d = 1, left = 0, right = 0, cur = 0;
    int ans = 0;
    while (x / d) {
        left = x / (d * 10);
        cur = (x / d) % 10;
        right = x % d;
        if (cur == 0) ans += left * d;
        else if (cur == 1) ans += (left * d + right + 1);
        else ans += (left + 1) * d;
        d *= 10;
    }
    cout << ans << endl;
    return 0;
}