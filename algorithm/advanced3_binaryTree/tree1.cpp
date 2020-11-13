#include <cstdio>
#include <queue>

using namespace std;

struct node {
    int data;
    node* lchild;
    node* rchild;
};

node* newNode(int v) {
    node* Node = new node;
    Node->data = v;
    Node->lchild = Node->rchild = NULL;
    return Node;
}

void search(node* root, int x, int newdata) {
    if(root == NULL) {
        return;
    }
    if(root->data == x) {
        root->data == newdata;
    }
    search(root->lchild, x, newdata);
    search(root->rchild, x, newdata);
}

void insert(node* &root, int x) {
    if(root == NULL) {
        root = newNode(x);
        return;
    }

    //true根据题目具体条件进行替换
    if(true) {
        search(root->lchild, x);
    } else {
        serach(root->rchild, x);
    }
}

node* create(int data[], int n) {
    node* root = NULL;
    for(int i = 0; i < n; i++) {
        insert(root, data[i]);
    }
    return root;
}

void preorder(node* root) {
    if(root == NULL) {
        return;
    }
    printf("%d", root->data);
    preorder(root->lchild);
    preorder(root->rchild);
}

void inorder(node* root) {
    if(root == NULL) {
        return;
    }
    inorder(root->lchild);
    printf("%d", root->data);
    inorder(root->rchild);
}

void posorder(node* root) {
    if(root == NULL) {
        return;
    }
    posorder(root->lchild);
    posorder(root->rchild);
    printf("%d", root->data);
}

void layerorder(node* root) {
    queue<node*> q;
    q.push(root);
    while(!q.empty()) {
        node* top = q.front();
        q.pop();
        printf("%d", top->data);
        if(top->lchild != NULL) {
            q.push(top->lchild);
        }
        if(top->rchild != NULL) {
            q.push(top->rchild);
        }
    }
}

int main() {
    return 0;
}