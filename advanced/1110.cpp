#include <iostream>
#include <string>

using namespace std;

struct node {
    int lchild, rchild;
} Tree[21];

int maxn = -1, ans = 0;
void dfs(int r, int index) {
    if (index > maxn) {
        maxn = index;
        ans = r;
    }
    if (Tree[r].lchild != -1) {
        dfs(Tree[r].lchild, index * 2);
    }
    if (Tree[r].rchild != -1) {
        dfs(Tree[r].rchild, index * 2 + 1);
    }
}

int main() {
    freopen("./sample_in/1110.txt", "r", stdin);
    int n, son[21] = {0};
    cin >> n;
    for (int i = 0; i < n; i++) {
        string l, r;
        cin >> l >> r;
        if (l != "-") {
            Tree[i].lchild = stoi(l);
            son[stoi(l)] = 1;
        } else {
            Tree[i].lchild = -1;
        }
        if (r != "-") {
            Tree[i].rchild = stoi(r);
            son[stoi(r)] = 1;
        } else {
            Tree[i].rchild = -1;
        }
    }

    int root = 0;
    while (son[root] != 0) {
        root++;
    }

    dfs(root, 1);
    if (maxn == n) {
        printf("YES %d\n", ans);
    } else {
        printf("NO %d\n", root);
    }

    return 0;
}