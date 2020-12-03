#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
struct node {
    int data;
    node *lchild, *rchild, *father;
};
int m, n;

node* newNode(int data, node* father) {
    node* Node = new node;
    Node->data = data;
    Node->father = father;
    Node->lchild = Node->rchild = NULL;
    return Node;
}

void create(node* &root, int data, node* father) {
    if (root == NULL) {
        root = newNode(data, father);
        return;
    }
    if (data < root->data) {
        create(root->lchild, data, root);
    } else {
        create(root->rchild, data, root);
    }
}

node* search(node* root, int target) {
    if (root == NULL) {
        return NULL;
    }
    if (target == root->data) {
        return root;
    } else if (target < root->data) {
        return search(root->lchild, target);
    } else {
        return search(root->rchild, target);
    }
}

int main() {
    freopen("./sample_in/1143.txt", "r", stdin);
    scanf("%d %d", &m, &n);
    node* root = NULL;
    while (n--) {
        int temp;
        scanf("%d", &temp);
        create(root, temp, NULL);
    }
    while (m--) {
        int u, v;
        scanf("%d %d", &u, &v);
        node *r1 = search(root, u), *r2 = search(root, v);
        if (r1 != NULL && r2 != NULL) {
            int ans = -1;
            bool hashTable[100010] = {false};
            while (r1->father != NULL) {
                hashTable[r1->data] = true;
                r1 = r1->father;
            }
            while (r2->father != NULL) {
                if (hashTable[r2->data]) {
                    ans = r2->data;
                    break;
                }
                r2 = r2->father;
            }
            if (ans == u) {
                printf("%d is an ancestor of %d.\n", u, v);
            } else if (ans == v) {
                printf("%d is an ancestor of %d.\n", v, u);
            } else {
                printf("LCA of %d and %d is %d.\n", u, v, ans);
            }
        } else if (r1 == NULL && r2 != NULL) {
            printf("ERROR: %d is not found.\n", u);
        } else if (r1 != NULL && r2 == NULL) {
            printf("ERROR: %d is not found.\n", v);
        } else if (r1 == NULL && r2 == NULL) {
            printf("ERROR: %d and %d are not found.\n", u, v);
        }
    }
    return 0;
}