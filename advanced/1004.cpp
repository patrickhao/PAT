#include <cstdio>
#include <vector>
#include <queue>

using namespace std;
const int maxn = 110;
int n, m;

struct node {
    int layer;
    vector<int> child;
} Tree[maxn];

int bfs(int root) {
    int maxLayer = 0;
    queue<int> q;
    q.push(root);
    Tree[root].layer = 0;
    while (!q.empty()) {
        int top = q.front();
        q.pop();
        for (int i = 0; i < Tree[top].child.size(); i++) {
            int c = Tree[top].child[i];
            Tree[c].layer = Tree[top].layer + 1;
            q.push(c);
            if (Tree[c].layer > maxLayer) {
                maxLayer = Tree[c].layer;
            }
        }
    }
    return maxLayer;
}

int main() {
    freopen("./sample_in/1004.txt", "r", stdin);
    int ans[maxn] = {0};

    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int id, num;
        scanf("%d %d", &id, &num);
        for (int j = 0; j < num; j++) {
            int c;
            scanf("%d", &c);
            Tree[id].child.push_back(c);
        }
    }

    int maxLayer = bfs(1);
    for (int i = 1; i <= n; i++) {
        if (Tree[i].child.size() == 0) {
            ans[Tree[i].layer]++;
        }
    }

    int outNum = 0;
    for (int i = 0; i <= maxLayer; i++) {
        printf("%d", ans[i]);
        if (outNum++ < maxLayer) {
            printf(" ");
        }
    }

    return 0;
}