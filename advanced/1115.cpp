#include <cstdio>
#include <queue>

using namespace std;

struct node {
    int data, layer;
    node *lchild, *rchild;
};

node* newNode(int d) {
    node* Node = new node;
    Node->data = d;
    Node->lchild = Node->rchild = NULL;
    return Node;
}

void insert(node* &root, int data) {
    if (root == NULL) {
        root = newNode(data);
        return;
    }
    if (data <= root->data) {
        insert(root->lchild, data);
    } else {
        insert(root->rchild, data);
    }
}

int maxLayer = 0;
void bfs1(node* root) {
    queue<node*> q;
    q.push(root);
    root->layer = 0;
    while (!q.empty()) {
        node* top = q.front();
        q.pop();
        if (top->layer > maxLayer) {
            maxLayer = top->layer;
        }
        if (top->lchild != NULL) {
            top->lchild->layer = top->layer + 1;
            q.push(top->lchild);
        }
        if (top->rchild != NULL) {
            top->rchild->layer = top->layer + 1;
            q.push(top->rchild);
        }
    }
}

int n1 = 0, n2 = 0;
void bfs2(node* root) {
    queue<node*> q;
    q.push(root);
    while (!q.empty()) {
        node* top = q.front();
        q.pop();
        if (top->layer == maxLayer) {
            n1++;
        } else if (top->layer == maxLayer - 1) {
            n2++;
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
    freopen("./sample_in/1115.txt", "r", stdin);
    int n;
    node* root = NULL;
    scanf("%d", &n);
    while (n--) {
        int temp;
        scanf("%d", &temp);
        insert(root, temp);
    }
    bfs1(root);
    bfs2(root);
    printf("%d + %d = %d", n1, n2, n1 + n2);

    return 0;
}