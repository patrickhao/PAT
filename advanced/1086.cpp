#include <cstdio>
#include <vector>

using namespace std;
int n;

struct node {
    int data;
    node *lchild, *rchlid;
};

node* newNode(int d) {
    node* Node = new node;
    Node->data = d;
    Node->lchild = Node->rchlid = NULL;
    return Node;
}

vector<int> v;
node* create(node* root, int index) {
    if (v[index] == -1) {
        return NULL;
    }
    root->data = v[index];
}

int b = 0;
void posOrder(node* root) {
    if (root == NULL) {
        return;
    }
    posOrder(root->lchild);
    b++;
    posOrder(root->lchild);
    b++;
    printf("%d", root->data);
    if (b < n - 1) {
        printf(" ");
    }
}

int main() {
    freopen("./sample_in/1086.txt", "r", stdin);
    node* root;
    int elem;
    char tag[5];
    scanf("%d", &n);
    posOrder(root);

    return 0;
}