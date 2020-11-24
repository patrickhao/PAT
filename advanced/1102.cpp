#include <cstdio>
#include <cctype>
#include <queue>

using namespace std;
const int maxn = 15;
int n, root;

struct node {
    int data;
    int lchild, rchild;
} Tree[maxn];

void levelOrder(int root) {
    int outNum = 0;
    queue<int> q;
    q.push(root);
    while (!q.empty()) {
        int top = q.front();
        q.pop();
        if (outNum++ < n - 1) {
            printf("%d ", Tree[top].data);
        } else {
            printf("%d\n", Tree[top].data);
        }
        if (Tree[top].lchild != -1) {
            q.push(Tree[top].lchild);
        }
        if (Tree[top].rchild != -1) {
            q.push(Tree[top].rchild);
        }
    }
}

int on = 0;
void inOrder(int root) {
    if (root == -1) {
        return;
    }
    inOrder(Tree[root].lchild);
    if (on++ < n - 1) {
        printf("%d ", Tree[root].data);
    } else {
        printf("%d\n", Tree[root].data);
    }
    inOrder(Tree[root].rchild);

}

int main() {
    freopen("./sample_in/1102.txt", "r", stdin);
    scanf("%d\n", &n);
    int hashTable[maxn] = {0};
    for (int i = 0; i < n; i++) {
        char cl, cr;
        scanf("%c %c\n", &cl, &cr);
        Tree[i].data = i;
        if (isdigit(cl)) {
            Tree[i].rchild = cl - '0';
            hashTable[cl - '0'] = 1;
        } else {
            Tree[i].rchild = -1;
        }
        if (isdigit(cr)) {
            Tree[i].lchild = cr - '0';
            hashTable[cr - '0'] = 1;
        } else {
            Tree[i].lchild = -1;
        }
    }
    for (int i = 0; i < n; i++) {
        if (hashTable[i] == 0) {
            root = i;
            break;
        }
    }
    levelOrder(root);
    inOrder(root);

    return 0;
}