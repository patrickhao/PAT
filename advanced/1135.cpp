#include <bits/stdc++.h>
using namespace std;

struct node {
	int val;
	node *left, *right;
};

node* newNode(int v) {
	node* root = new node;
	root->val = v;
	root->left = root->right = NULL;
	return root;
}

void insert(node* &root, int v) {
	if (root == NULL) {
		root = newNode(v);
		return;
	}
	if (abs(v) < abs(root->val)) insert(root->left, v);
	else insert(root->right, v);
}

bool tag = true;
vector<int> temp;
void dfs(node* root, int cnt) {
	if (root == NULL) {
		temp.push_back(cnt);
		return;
	}
	if (root->val > 0) {
		dfs(root->left, cnt + 1);
		dfs(root->right, cnt + 1);
	} else {
		if (root->left != NULL && root->left->val < 0) tag = false;
		if (root->right != NULL && root->right->val < 0) tag = false;
		dfs(root->left, cnt);
		dfs(root->right, cnt);
	}
}

void solve() {
	int n; cin >> n;
	node* root = NULL;
	while (n--) {
		int temp; cin >> temp;
		insert(root, temp);
	}
	if (root->val > 0) {
		tag = true; temp.clear();
		dfs(root, 0);
		for (int i = 0; i < temp.size() - 1; i++) if (temp[i] != temp[i + 1]) tag = false;
		cout << (tag ? "YES" : "NO") << endl;
	} else cout << "NO" << endl;

}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) solve();
	return 0;
}