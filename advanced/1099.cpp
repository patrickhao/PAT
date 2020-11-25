#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;
const int maxn = 110;
int n, arr[maxn];

struct node {
    int data;
    int lchild, rchild;
} Tree[maxn];

int ind = 0;
void create(int root) {
    if (root == -1) {
        return;
    }
    create(Tree[root].lchild);
    Tree[root].data = arr[ind++];
    create(Tree[root].rchild);
}

void levelOrder(int root) {
    queue<int> q;
    int outNum = 0;
    q.push(root);
    while (!q.empty()) {
        int top = q.front();
        q.pop();
        printf("%d", Tree[top].data);
        if (++outNum != n) {
            printf(" ");
        }
        if (Tree[top].lchild != -1) {
            q.push(Tree[top].lchild);
        }
        if (Tree[top].rchild != -1) {
            q.push(Tree[top].rchild);
        }
    }
}

int main() {
    freopen("./sample_in/1099.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &Tree[i].lchild, &Tree[i].rchild);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }
    sort(arr, arr + n);
    create(0);
    levelOrder(0);

    return 0;
}