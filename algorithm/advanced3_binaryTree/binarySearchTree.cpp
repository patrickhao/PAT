#include <cstdio>

struct node {
    int data;
    node *lchild;
    node *rchild;
};

node* newNode(int x) {
    node* Node = new node;
    Node->data = x;
    Node->lchild = Node->rchild = NULL;
    return Node;
}

void search(node* root, int x) {
    if(root == NULL) {
        printf("failed\n");
        return;
    }
    if(x == root->data) {
        printf("succeed\n");
        printf("%d\n", root->data);
    } else if(x < root->data) {
        search(root->lchild, x);
    } else {
        search(root->rchild, x);
    }
}

void insert(node* &root, int x) {
    if(root == NULL) {
        root = newNode(x);
        return;
    }
    if(x == root->data) {
        return;
    } else if(x < root->data) {
        insert(root->lchild, x);
    } else {
        insert(root->rchild, x);
    }
}

node* findMax(node* root) {
    while(root->rchild != NULL) {
        root = root->rchild;
    }
    return root;
}

node* findMin(node* root) {
    while(root->lchild != NULL) {
        root = root->lchild;
    }
    return root;
}

void deleteNode(node* &root, int x) {
    if(root == NULL) {
        return;
    }
    if(x == root->data) {
        if(root->lchild == NULL && root->rchild == NULL) {
            root = NULL;
            return;
        } else if(root->lchild->lchild != NULL) {
            node* pre = findMax(root->lchild);
            root->data = pre->data;
            deleteNode(root->lchild, pre->data);
        } else {
            node* next = findMin(root->rchild);
            root->data = next->data;
            deleteNode(root->rchild, next->data);
        }
    } else if(x < root->data) {
        deleteNode(root->lchild, x);
    } else {
        deleteNode(root->rchild, x);
    }

}

void inorder(node* root) {
    if(root == NULL) {
        return;
    }

    inorder(root->lchild);
    printf("%d ", root->data);
    inorder(root->rchild);
}

node* create(int data[], int n) {
    node* root = NULL;
    for(int i = 0; i < n; i++) {
        insert(root, data[i]);
    }
    return root;
}

int main() {
    int arr[7] = {5, 3, 7, 4, 2, 8, 6};
    node* root = create(arr, 7);
    search(root, 3);
    inorder(root);
    printf("\n");
    deleteNode(root, 6);
    inorder(root);
    printf("\n");
    return 0;
}