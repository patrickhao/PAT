#include <bits/stdc++.h>
using namespace std;
vector<int> pre, in, post;
int n;
bool u = true;

void getIn(int preL, int preR, int postL, int postR) {
	if (preL == preR) {
		in.push_back(pre[preL]);
		return;
	}
	if (pre[preL] == post[postR]) {
		int i = preL + 1;
		while (i <= preR && pre[i] != post[postR - 1]) {
			i++;
		}
		if (i - preL > 1) {
			getIn(preL + 1, i - 1, postL, postL + (i - preL - 1) - 1);
		} else {
			u = false;
		}
		in.push_back(pre[preL]);
		getIn(i, preR, postL + (i - preL - 1), postR - 1);
	}
	
}

int main() {
	freopen("./sample_in/1119.txt", "r", stdin);
	cin >> n;
	pre.resize(n);
	post.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> pre[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> post[i];
	}
	getIn(0, n - 1, 0, n - 1);
	if (u) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	for (int i = 0; i < in.size(); i++) {
		cout << in[i];
		if (i < in.size() - 1) {
			cout << " ";
		} else {
			cout << endl;
		}
	}
	return 0;
}
