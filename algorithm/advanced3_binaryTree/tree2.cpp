#include <cstdio>

struct node {
    char data;
    node* lchild;
    node* rchild;
};

char pre[6] = {'A', 'B', 'D', 'E', 'C', 'F'};
char in[6] = {'D', 'B', 'E', 'A', 'C', 'F'};
char pos[6] = {'D', 'E', 'B', 'F', 'C', 'A'};

//pre + in
node* create1(int preL, int preR, int inL, int inR) {
    if(preL > preR) {
        return NULL;
    }
    node* root = new node;
    root->data = pre[preL];
    int k;
    for(k = inL; k <= inR; k++) {
        if(in[k] == pre[preL]) {
            break;
        }
    }
    int numLeft = k - inL;
    root->lchild = create1(preL + 1, preL + numLeft, inL, k - 1);
    root->rchild = create1(preL + numLeft + 1, preR, k + 1, inR);
    return root;
}

//pos + in
node* create2(int posL, int posR, int inL, int inR) {
    if(posL > posR) {
        return NULL;
    }
    node* root = new node;
    root->data = pos[posR];
    int k;
    for(k = inL; k <= inR; k++) {
        if(in[k] == pos[posR]) {
            break;
        }
    }
    int numLeft = k - inL;
    //注意边界
    root->lchild = create2(posL, posL + numLeft - 1, inL, k - 1);
    root->rchild = create2(posL + numLeft, posR - 1, k + 1, inR);
    return root;
}

void preorder(node* root) {
    if(root == NULL) {
        return;
    }
    printf("%c ", root->data);
    preorder(root->lchild);
    preorder(root->rchild);
}

void posorder(node* root) {
    if(root == NULL) {
        return;
    }
    posorder(root->lchild);
    posorder(root->rchild);
    printf("%c ", root->data);
}


int main() {
    node* root1 = create1(0, 5, 0, 5);
    posorder(root1);
    printf("\n");
    node* root2 = create2(0, 5, 0, 5);
    preorder(root2);
    return 0;
}