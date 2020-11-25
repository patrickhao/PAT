#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;
const int maxn = 1010;
int n, arr[maxn];

struct node {
    int data;
    node *lchild, *rchild;
};

node* newNode(int data) {
    node* Node = new node;
    Node->data = data;
    Node->lchild = Node->rchild = NULL;
    return Node;
}

node* createCBT() {
    int num = 0;
    queue<node*> q;
    node* root = newNode(0);
    if (++num == n) {
        return root;
    }
    q.push(root);
    while (!q.empty()) {
        node* top = q.front();
        q.pop();
        top->lchild = newNode(0);
        q.push(top->lchild);
        if (++num == n) {
            return root;
        }
        top->rchild = newNode(0);
        q.push(top->rchild);
        if (++num == n) {
            return root;
        }
    }
    return root;
}

int ind = 0;
void createBST(node* root) {
    if (root == NULL) {
        return;
    }
    createBST(root->lchild);
    root->data = arr[ind++];
    createBST(root->rchild);
}

int outNum = 0;
void levelOrder(node* root) {
    queue<node*> q;
    q.push(root);
    while (!q.empty()) {
        node* top = q.front();
        q.pop();
        printf("%d", top->data);
        if (outNum++ < n - 1) {
            printf(" ");
        }
        if (top->lchild != NULL) {
            q.push(top->lchild);
        }
        if (top->rchild != NULL) {
            q.push(top->rchild);
        }
    }
}

int main() {
    freopen("./sample_in/1064.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    } 
    sort(arr, arr + n);
    node* root = createCBT();
    createBST(root);
    levelOrder(root);

    return 0;
}