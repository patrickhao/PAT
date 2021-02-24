#include <bits/stdc++.h>
using namespace std;

struct node {
    int val;
    node *left, *right;
};

int n;
vector<int> inorder, postorder;

node* create(int il, int ir, int pl, int pr) {
    if (il > ir) return NULL;

    int cur = il;
    while (inorder[cur] != postorder[pr]) cur++;
    int leftNum = cur - il;

    node* root = new node();
    root->val = postorder[pr];
    root->left = create(il, cur - 1, pl, pl + leftNum - 1);
    root->right = create(cur + 1, ir, pl + leftNum, pr - 1);
    return root;
}

int tag = 0, cnt = 0;
void bfs(node* root) {
    queue<node*> q;
    q.push(root);
    while (!q.empty()) {
        vector<int> temp;
        int t = q.size();
        while (t--) {
            node* cur = q.front();
            q.pop();
            temp.push_back(cur->val);
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }

        if (tag == 1 || cnt == 0) {
            for (int i = 0; i < temp.size(); i++) {
                cout << temp[i];
                cout << (++cnt < n ? " " : "\n");
            }
        } else {
            for (int i = temp.size() - 1; i >= 0; i--) {
                cout << temp[i];
                cout << (++cnt < n ? " " : "\n");
            }
        }
        tag ^= 1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n; 
    inorder.resize(n); postorder.resize(n);
    for (auto &v : inorder) cin >> v;
    for (auto &v : postorder) cin >> v;

    node* root = create(0, n - 1, 0, n - 1);

    bfs(root);
    return 0;
}