#include <bits/stdc++.h>
using namespace std;
const int maxn = 33;
int n, k;
struct node {
	int data;
	node *lchild, *rchild;
};

node* newNode(int data) {
	node* Node = new node;
	Node->data = data;
	Node->lchild = Node->rchild = NULL;
	return Node;
}

void create(node* &root, int data) {
	if (root == NULL) {
		root = newNode(data);
		return;
	}	
	if (abs(data) < abs(root->data)) {
		create(root->lchild, data);
	} else {
		create(root->rchild, data);
	}
}

bool judge1(node* root) {
	if (root->data < 0) {
		if ((root->lchild != NULL && root->lchild->data < 0) || (root->rchild != NULL && root->rchild->data < 0)) {
			return false;
		} else {
			return true;
		}
	} else {
		if (root->lchild != NULL) {
			return judge1(root->lchild);
		}
		if (root->rchild != NULL) {
			return judge1(root->rchild);
		}
	}
	return true;
}

int bn = -1;
bool flag = true;
void judge2(node* root, int n) {
	if (root == NULL) {
		if (n != bn) {
			if (bn == -1) {
				bn = n;
			} else {
				flag = false;
			}
		}
		return;
	}
	if (root->data > 0) {
		judge2(root->lchild, n + 1);
		judge2(root->rchild, n + 1);
	} else {
		judge2(root->lchild, n);
		judge2(root->rchild, n);
	}
}

int main() {
	freopen("./sample_in/1135.txt", "r", stdin);
	scanf("%d", &k);
	while (k--) {
		scanf("%d", &n);
		node* root = NULL;
		for (int i = 0; i < n; i++) {
			int temp;
			scanf("%d", &temp);
			create(root, temp);
		}
		if (root->data > 0) {
			if (judge1(root)) {
				flag = true;
				judge2(root, 0);
				if (flag) {
					printf("Yes\n");
				} else {
					printf("No\n");
				}
			} else {
				printf("No\n");
			}
		} else {
			printf("No\n");
		}
	}
	return 0;
}
