#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> a;
vector<int> path;
vector<int> ans;
void dfs(int ind, int sum) {
    if (ans.size() != 0) return;
    if (sum == m) ans = path;
    if (sum > m || ind >= n) return;
    if (ans.size() == 0) {
        path.push_back(a[ind]);
        dfs(ind + 1, sum + a[ind]);
        path.pop_back();
        dfs(ind + 1, sum);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    a.resize(n);
    for (auto &v : a) cin >> v;
    sort(a.begin(), a.end());
    dfs(0, 0);
    if (ans.size() == 0) cout << "No Solution" << endl;
    else {
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i];
            cout << (i < ans.size() - 1 ? " " : "\n");
        }
    }

    return 0;
}