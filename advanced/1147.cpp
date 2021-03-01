#include <bits/stdc++.h>
using namespace std;
int n;

bool judgeMax(int root, const vector<int>& heap) {
	if (root * 2 > n) return true;
	if (heap[root] < heap[root * 2] || (root * 2 + 1 <= n && heap[root] < heap[root * 2 + 1])) return false;
	return judgeMax(root * 2, heap) && judgeMax(root * 2 + 1, heap);
}

bool judgeMin(int root, const vector<int>& heap) {
	if (root * 2 > n) return true;
	if (heap[root] > heap[root * 2] || (root * 2 + 1 <= n && heap[root] > heap[root * 2 + 1])) return false;
	return judgeMin(root * 2, heap) && judgeMin(root * 2 + 1, heap);
}

int cnt = 0;
void postOrder(int root, const vector<int>& heap) {
	if (root > n) return;
	postOrder(root * 2, heap);
	postOrder(root * 2 + 1, heap);
	cout << heap[root];
	cout << (++cnt < n ? " " : "\n");
}

void solve() {
	vector<int> heap(n + 1, -1);
	for (int i = 1; i <= n; i++) cin >> heap[i];
	cnt = 0;
	if (judgeMax(1, heap)) cout << "Max Heap" << endl;
	else if (judgeMin(1, heap)) cout << "Min Heap" << endl;
	else cout << "Not Heap" << endl;
	postOrder(1, heap);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t; cin >> t; cin >> n;
	while (t--) solve();

	return 0;
}