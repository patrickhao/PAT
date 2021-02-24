#include <bits/stdc++.h>
using namespace std;

void cal(int n, int& a, int& b) {
    int cur = abs(a - b);
    for (int i = 1; i <= n; i++) {
        if (n % i == 0 && abs(i - n / i) < cur) {
            cur = abs(i - n / i);
            a = min(i, n / i);
            b = max(i, n / i);
        }
    }
}

bool judge(const vector<vector<int>>& v, int x, int y) {
    int b = v.size(), a = v[0].size();
    if (x < 0 || x >= a || y < 0 || y >= b) return false;
    if (v[y][x] > 0) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> v(n);
    for (int &i : v) cin >> i;
    sort(v.rbegin(), v.rend());
    int a = 1, b = n;
    cal(n, a, b);

    int X[] = {1, 0, -1, 0};
    int Y[] = {0, 1, 0, -1};
    vector<vector<int>> ans(b, vector<int>(a, -1));

    int cur = 0, ind = 0;
    int x = -1, y = 0;

    int cnt = 0;
    while (ind < n) {
        int nx = x + X[cur];
        int ny = y + Y[cur];
        if (judge(ans, nx, ny)) {
            ans[ny][nx] = v[ind++];
            x = nx; y = ny;
        } else cur = (cur + 1) % 4;
    }

    for (auto v : ans) {
        for (int i = 0; i < v.size(); i++) {
            cout << v[i];
            cout << (i < v.size() - 1 ? " " : "\n");
        }
    }

    return 0;
}