#include <cstdio>
#include <vector>

using namespace std;
int n;
int A[80];

struct node {
    int data;
    node *lchild, *rchild;
};

node* newNode(int d) {
    node* Node = new node;
    Node->data = d;
    Node->lchild = Node->rchild = NULL;
    return Node;
}

int ind = 0;
void create(node* &root) {
    if (A[ind] == -1 || ind >= 2 * n) {
        return;
    }
    root = newNode(A[ind]);
    ind++;
    create(root->lchild);
    ind++;
    create(root->rchild);
}

int b = 0;
void posOrder(node* root) {
    if (root == NULL) {
        return;
    }
    posOrder(root->lchild);
    posOrder(root->rchild);
    printf("%d", root->data);
    if (b++ < n - 1) {
        printf(" ");
    }
}

int main() {
    freopen("./sample_in/1086.txt", "r", stdin);
    node* root = NULL;
    scanf("%d", &n);
    for (int i = 0; i < 2 * n; i++) {
        int elem;
        char tag[5];
        scanf("%s", tag);
        if (tag[1] == 'u') {
            scanf("%d", &elem);
            A[i] = elem;
        } else {
            A[i] = -1;
        }
    }
    create(root);
    posOrder(root);

    return 0;
}