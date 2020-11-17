#include <cstdio>
#include <algorithm>

using namespace std;

struct node {
    int v, height;
    node *lchild, *rchild;
};

node* newNode(int v) {
    node* Node = new node;
    Node->v = v;
    Node->height = 1;
    Node->lchild = Node->rchild = NULL;
    return Node;
}

int getHeight(node* root) {
    if(root == NULL) {
        return 0;
    }
    return root->height;
}

int getBalanceFactor(node* root) {
    return getHeight(root->lchild) - getHeight(root->rchild);
}

void updateHeight(node* root) {
    root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}

void search(node* root, int x) {
    if(root == NULL) {
        printf("failed\n");
        return;
    }
    if(x == root->v) {
        printf("succeed\n");
        printf("%d\n", root->v);
    } else if(x < root->v) {
        search(root->lchild, x);
    } else {
        search(root->rchild, x);
    }
}

//左旋
void leftRotation(node* &root) {
    node* temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

//右旋
void rightRotation(node* &root) {
    node* temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

void insert(node* &root, int v) {
    if(root == NULL) {
        root = newNode(v);
        return;
    }
    if(v < root->v) {
        insert(root->lchild, v);
        updateHeight(root);
        if(getBalanceFactor(root) == 2) {
            if(getBalanceFactor(root->lchild) == 1) {
                rightRotation(root);
            } else if(getBalanceFactor(root->lchild) == -1) {
                leftRotation(root->rchild);
                rightRotation(root);
            }
        }
    } else {
        insert(root->rchild, v);
        updateHeight(root);
        if(getBalanceFactor(root) == -2) {
            if(getBalanceFactor(root->rchild) == 1) {
                rightRotation(root->lchild);
                leftRotation(root);
            } else if(getBalanceFactor(root->rchild) == -1){
                leftRotation(root);
            }
        }
    }
}

node* create(int data[], int n) {
    node* root = NULL;
    for(int i = 0; i < n; i++) {
        insert(root, data[i]);
    }
    return root;
}

void inorder(node* root) {
    if(root == NULL) {
        return;
    }
    inorder(root->lchild);
    printf("%d ", root->v);
    inorder(root->rchild);
}

int main() {
    int arr[6] = {1, 2, 3, 4, 5, 6};
    node* root = create(arr, 6);
    inorder(root);
    return 0;
}