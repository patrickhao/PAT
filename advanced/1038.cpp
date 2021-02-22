#include <bits/stdc++.h>
using namespace std;

bool cmp(string s1, string s2) {
     int n = s1.length(), m = s2.length();
     int i = 0, j = 0;
     while (i < n && j < m) {
         if (s1[i] != s2[j]) return s1[i] < s2[j];
         i++; j++;
     }
     if (i < n) return s1[m] <= s2[0];
     if (j < m) return s1[0] < s2[n];
     return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<string> a(n);
    for (auto &v : a) cin >> v;
    sort(a.begin(), a.end(), cmp);

    string ans = "";
    for (auto v : a) ans += v;
    while (*ans.begin() == '0' && ans.length() > 1) ans.erase(ans.begin());
    cout << ans << endl;

    return 0;
}