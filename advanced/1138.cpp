#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int maxn = 50010;
struct node {
    int data;
    node *lchild, *rchild;
};
int pre[maxn], in[maxn];

node* newNode(int data) {
    node* Node = new node;
    Node->data = data;
    Node->lchild = Node->rchild = NULL;
    return Node;
}

void create(node* &root, int l1, int r1, int l2, int r2) {
    if (l1 > r1 || l2 > r2) {
        return;
    }
    root = newNode(pre[l1]);
    int leftNum = 0;
    for (; leftNum + l2 <= r2; leftNum++) {
        if (in[leftNum + l2] == pre[l1]) {
            break;
        }
    }
    create(root->lchild, l1 + 1, l1 + leftNum, l2, l2 + leftNum - 1);
    create(root->rchild, l1 + leftNum + 1, r1, l2 + leftNum + 1, r2);
}

int first = -1;
void postOrder(node* root) {
    if (root == NULL) {
        return;
    }
    postOrder(root->lchild);
    postOrder(root->rchild);
    if (first < 0) {
        first = root->data;
    }
}

int main() {
    freopen("./sample_in/1138.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", pre + i);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", in + i);
    }
    node* root = NULL;
    create(root, 0, n - 1, 0, n - 1);
    postOrder(root);
    printf("%d\n", first);

    return 0;
}