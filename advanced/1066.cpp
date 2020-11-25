#include <cstdio>
#include <algorithm>

using namespace std;
const int maxn = 30;

struct node {
    int data, height;
    node *lchild, *rchild;
};

node* newNode(int data) {
    node* Node = new node;
    Node->data = data;
    Node->height = 1;
    Node->lchild = Node->rchild = NULL;
    return Node;
}

int getHeight(node* root) {
    if (root == NULL) {
        return 0;
    }
    return root->height;
}

int getBF(node* root) {
    return getHeight(root->lchild) - getHeight(root->rchild);
}

void updateHeight(node* root) {
    root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}

void L(node* &root) {
    node* temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

void R(node* &root) {
    node* temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

void insert(node* &root, int data) {
    if (root == NULL) {
        root = newNode(data);
        return;
    }
    if (data < root->data) {
        insert(root->lchild, data);
        updateHeight(root);
        if (getBF(root) == 2) {
            if (getBF(root->lchild) == 1) {
                //LL
                R(root);
            } else if (getBF(root->lchild) == -1){
                //LR
                L(root->lchild);
                R(root);
            }
        }
    } else {
        insert(root->rchild, data);
        updateHeight(root);
        if (getBF(root) == -2){
            if (getBF(root->rchild) == 1) {
                //RL
                R(root->rchild);
                L(root);
            } else if (getBF(root->rchild) == -1){
                //RR
                L(root);
            }
        }
    }
}

node* create(int arr[], int n) {
    node* root = NULL;
    for (int i = 0; i < n; i++) {
        insert(root, arr[i]);
    }
    return root;
}

int main() {
    freopen("./sample_in/1066.txt", "r", stdin);
    int n, arr[maxn];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }
    node* root = create(arr, n);
    printf("%d\n", root->data);

    return 0;
}