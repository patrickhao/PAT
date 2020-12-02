#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
const int maxn = 10010;
vector<int> Adj[maxn];
bool gender[maxn] = {false};
int n, m;

bool cmp(vector<int> v1, vector<int> v2) {
    if (v1[0] != v2[0]) {
        return v1[0] < v2[0];
    } else {
        return v1[1] < v2[1];
    }
}

vector<int> path;
vector<vector<int>> ans;
int n1, n2;
void dfs(int depth, int cur) {
    if (depth == 3) {
        if (cur == n2 && gender[path[0]] == gender[n1] && gender[path[1]] == gender[n2]) {
            ans.push_back(path);
        }
        return;
    }
    for (int i = 0; i < Adj[cur].size(); i++) {
        path.push_back(Adj[cur][i]);
        dfs(depth + 1, Adj[cur][i]);
        path.pop_back();
    }
}

int main() {
    freopen("./sample_in/1139.txt", "r", stdin);
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v;
        char s1[6], s2[6];
        scanf("%s %s", s1, s2);
        sscanf(s1, "%d", &u);
        sscanf(s2, "%d", &v);
        gender[abs(u)] = s1[0] == '-' ? true : false;
        gender[abs(v)] = s2[0] == '-' ? true : false;
        Adj[abs(u)].push_back(abs(v));
        Adj[abs(v)].push_back(abs(u));
    }
    int k;
    scanf("%d", &k);
    while (k--) {
        ans.clear();
        scanf("%d %d", &n1, &n2);
        n1 = abs(n1);
        n2 = abs(n2);
        dfs(0, n1);
        sort(ans.begin(), ans.end(), cmp);
        printf("%d\n", ans.size());
        for (int i = 0; i < ans.size(); i++) {
            printf("%04d %04d\n", ans[i][0], ans[i][1]);
        }
    }

    return 0;
}