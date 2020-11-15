#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 110;
int n, m, s;
vector<vector<int>> ans;
vector<int> path;

struct node {
    int weight;
    vector<int> child;    
} Node[maxn];

bool cmp(vector<int> a1, vector<int> a2) {
    for(int i = 0; i < min(a1.size(), a2.size()); i++) {
        if(a1[i] != a2[i]) {
            return a1[i] > a2[i];
        }
    }
    return false;
}

void dfs(int root, int w) {
    w += Node[root].weight;
    path.push_back(Node[root].weight);
    if(Node[root].child.empty()) {
        if(w == s) {
            ans.push_back(path);
        }
    }
    for(int i = 0; i < Node[root].child.size(); i++) {
        dfs(Node[root].child[i], w);
    }
    path.pop_back();
}

int main() {
    freopen("./sample_in/1053.txt", "r", stdin);
    scanf("%d %d %d", &n, &m, &s);
    for(int i = 0; i < n; i++) {
        scanf("%d", &Node[i].weight);
    }
    for(int i = 0; i < m; i++) {
        int ind, num, child;
        scanf("%d %d", &ind, &num);
        while(num--) {
            scanf("%d", &child);
            Node[ind].child.push_back(child);
        }
    }
    dfs(0, 0);
    sort(ans.begin(), ans.end(), cmp);
    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[i].size(); j++) {
            printf("%d", ans[i][j]);
            if(j != ans[i].size() - 1) {
                printf(" ");
            } else {
                printf("\n");
            }
        }
        
    }

    return 0;
}