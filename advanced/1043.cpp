#include <cstdio>

struct node {
    int data;
    node* lchild;
    node* rchild;
};

int n, arr[1010] = {0}, indAns = 0, ans[1010] = {0};
bool flag = true;

node* newNode(int x) {
    node* Node = new node;
    Node->data = x;
    Node->lchild = Node->rchild = NULL;
    return Node;
}

void insert(node* &root, int x) {
    if(root == NULL) {
        root = newNode(x);
        return;
    }
    if(x < root->data) {
        insert(root->lchild, x);
    } else {
        insert(root->rchild, x);
    }
}

node* create(int data[], int n) {
    node* root = NULL;
    for(int i = 0; i < n; i++) {
        insert(root, data[i]);
    }
    return root;
}

void preorder1(node* root) {
    if(root == NULL) {
        return;
    }
    if(arr[indAns] != root->data) {
        flag = false;
    }
    indAns++;
    preorder1(root->lchild);
    preorder1(root->rchild);
}

void preorder2(node* root) {
    if(root == NULL) {
        return;
    }
    if(arr[indAns] != root->data) {
        flag = false;
    }
    indAns++;
    preorder2(root->rchild);
    preorder2(root->lchild);
}

void posorder1(node* root) {
    if(root == NULL) {
        return;
    }
    posorder1(root->lchild);
    posorder1(root->rchild);
    ans[indAns++] = root->data;
}

void posorder2(node* root) {
    if(root == NULL) {
        return;
    }
    posorder2(root->rchild);
    posorder2(root->lchild);
    ans[indAns++] = root->data;
}

int main() {
    freopen("./sample_in/1043.txt", "r", stdin);
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }
    
    int tag = 0;
    node* root = create(arr, n);
    indAns = 0;
    preorder1(root);
    if(!flag) {
        flag = true;
        indAns = 0;
        preorder2(root);
        if(flag) {
            tag = 2;
        }
    } else {
        tag = 1;
    }
    if(flag) {
        printf("YES\n");
        indAns = 0;
        if(tag == 1) {
            posorder1(root);
        } else {
            posorder2(root);
        }
        for(int i = 0; i < indAns - 1; i++) {
            printf("%d ", ans[i]);
        }
        printf("%d\n", ans[indAns - 1]);
    } else {
        printf("NO\n");
    }
    return 0;
}