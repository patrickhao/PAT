#include <cstdio>
#include <vector>
#include <queue>

using namespace std;
const int maxn = 110;
int n, m;
vector<int> ge(maxn, 0);

struct node {
    int g;
    vector<int> child;
} Tree[maxn];

void bfs(int root) {
    queue<int> q;
    q.push(root);
    Tree[root].g = 1;
    while (!q.empty()) {
        int top = q.front();
        ge[Tree[top].g]++;
        q.pop();
        if (Tree[top].child.size() != 0) {
            for (int i = 0; i < Tree[top].child.size(); i++) {
                int c = Tree[top].child[i];
                Tree[c].g = Tree[top].g + 1;
                q.push(c);
            }
        }
    }
}

int main() {
    freopen("./sample_in/1094.txt", "r", stdin);
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        int id, num;
        scanf("%d %d", &id, &num);
        for (int j = 0; j < num; j++) {
            int c;
            scanf("%d", &c);
            Tree[id].child.push_back(c);
        }
    }
    bfs(1);
    int ai = 1;
    for (int i = 0; i < n; i++) {
        if (ge[i] > ge[ai]) {
            ai = i;
        }
    }
    printf("%d %d", ge[ai], ai);

    return 0;
}