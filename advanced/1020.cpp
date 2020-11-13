#include <cstdio>
#include <queue>

using namespace std;

const int maxn = 31;
struct node {
    int data;
    node* lchild;
    node* rchild;
};

int pos[maxn] = {0};
int in[maxn] = {0};
int ans[maxn] = {0};
int ind = 0;

node* create(int posL, int posR, int inL, int inR) {
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
    root->lchild = create(posL, posL + numLeft - 1, inL, k - 1);
    root->rchild = create(posL + numLeft, posR - 1, k + 1, inR);
    return root;
}

void layerOrder(node* root) {
    queue<node*> q;
    q.push(root);
    while(!q.empty()) {
        node* top = q.front();
        q.pop();
        ans[ind++] = top->data;
        if(top->lchild != NULL) {
            q.push(top->lchild);
        }
        if(top->rchild != NULL) {
            q.push(top->rchild);
        }
    }
}

int main() {
    freopen("./sample_in/1020.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", pos + i);
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", in + i);
    }
    node* root = create(0, n - 1, 0, n - 1);
    layerOrder(root);
    for(int i = 0; i < ind - 1; i++) {
        printf("%d ", ans[i]);
    }
    printf("%d", ans[n - 1]);
    return 0;
}