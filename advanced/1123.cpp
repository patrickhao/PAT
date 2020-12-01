#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct node {
	int data, height, index;
	node *lchild, *rchild;
};
int n;

node* newNode(int d) {
	node* Node = new node;
	Node->data = d;
	Node->height = 1;
	Node->lchild = Node->rchild = NULL;
	return Node;
}

int getHeight(node* root) {
	if (root == NULL) {
		return 0;
	}
	return root->height;
}

void updateHeight(node* root) {
	root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}

int getBalanceFactor(node* root) {
	return getHeight(root->lchild) - getHeight(root->rchild); 
}

void L(node* &root) {
	node* temp = root->rchild;
	root->rchild = temp->lchild;
	temp->lchild = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}

void R(node* &root) {
	node* temp = root->lchild;
	root->lchild = temp->rchild;
	temp->rchild = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}

void insert(node* &root, int data) {
	if (root == NULL) {
		root = newNode(data);
		return;
	}
	if (data < root->data) {
		insert(root->lchild, data);
		updateHeight(root);
		if (getBalanceFactor(root) == 2) {
			if (getBalanceFactor(root->lchild) == 1) {
				R(root);
			} else if (getBalanceFactor(root->lchild) == -1) {
				L(root->lchild);
				R(root);
			}	
		}
	} else {
		insert(root->rchild, data);
		updateHeight(root);
		if (getBalanceFactor(root) == -2) {
			if (getBalanceFactor(root->rchild) == 1) {
				R(root->rchild);
				L(root);
			} else if (getBalanceFactor(root->rchild) == -1) {
				L(root);
			}
		}
	}
}

node* create(vector<int> data) {
	node* root = NULL;
	for (int i = 0; i < data.size(); i++) {
		insert(root, data[i]);
	}
	return root;
}

int on = 0, maxIndex = 0;
void levelOrder(node* root) {
	queue<node*> q;
	q.push(root);
	root->index = 1;
	while (!q.empty()) {
		node* top = q.front();
		q.pop();
		if (top->index > maxIndex) {
			maxIndex = top->index;
		}
		cout << top->data;
		if (++on < n) {
			cout << " ";
		} else {
			cout << endl;
		}
		if (top->lchild != NULL) {
			top->lchild->index = top->index * 2;
			q.push(top->lchild);
		}
		if (top->rchild != NULL) {
			top->rchild->index = top->index * 2 + 1;
			q.push(top->rchild);
		}
	}
}

int main() {
	freopen("./sample_in/1123.txt", "r", stdin);
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i< n; i++) {
		cin >> arr[i];
	}
	node* root = create(arr);
	levelOrder(root);
	if (maxIndex == n) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}

	return 0;
}
