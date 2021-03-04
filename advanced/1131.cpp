#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 50;
const int INF = 1e9;
vector<int> Adj[MAXN];
unordered_map<int, int> line;
bool vis[MAXN] = {false};
int minCnt, minTransfrom, a, b, n;
vector<int> ans, temp;

int getTransform(const vector<int>& a) {
    int preLine = 0, cnt = -1;
    for (int i = 1; i < a.size(); i++) {
        if (line[10000 * a[i - 1] + a[i]] != preLine) {
            preLine = line[10000 * a[i - 1] + a[i]];
            cnt++;
        }
    }
    return cnt;
}

void dfs(int cur, int cnt) {
    if (cur == b && (cnt < minCnt || (cnt == minCnt && getTransform(temp) < minTransfrom))) {
        ans = temp;
        minCnt = cnt;
        minTransfrom = getTransform(temp);
        return;
    }
    if (cur == b) return;
    for (auto v : Adj[cur]) {
        if (vis[v] == false) {
            temp.push_back(v);
            vis[v] = true;
            dfs(v, cnt + 1);
            temp.pop_back();
            vis[v] = false;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int m; cin >> m;
        vector<int> temp(m);
        for (auto &v : temp) cin >> v;
        for (int j = 0; j < temp.size() - 1; j++) {
            int u = temp[j], v = temp[j + 1];
            Adj[u].push_back(v);
            Adj[v].push_back(u);
            line[10000 * u + v] = line[v * 10000 + u] = i;
        }
    }

    int t; cin >> t;
    while (t--) {
        cin >> a >> b;
        ans.clear(); temp.clear();
        minCnt = minTransfrom = INF;
        temp.push_back(a);
        vis[a] = true;
        dfs(a, 0);
        vis[a] = false;
        cout << minCnt << endl;
        int preStation = a, preLine = 0;
        for (int i = 1; i < ans.size(); i++) {
            if (line[10000 * ans[i] + ans[i - 1]] != preLine) {
                if (preLine != 0) printf("Take Line#%d from %04d to %04d.\n", preLine, preStation, ans[i - 1]);
                preStation = ans[i - 1];
                preLine = line[10000 * ans[i] + ans[i - 1]];
            }
        }
        printf("Take Line#%d from %04d to %04d.\n", preLine, preStation, ans.back());
    }
    
    return 0;
}