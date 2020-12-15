#include <bits/stdc++.h>
using namespace std;
const int maxn = 512;
vector<int> Adj[maxn];
int n, m;

int st, ed;
void dfs(int cur) {
}

int main() {
	freopen("./sample_in/1126.txt", "r", stdin);
	cin >> n >> m;
	while (m--) {
		int u, v;
		cin >> u >> v;
		Adj[u].push_back(v);
		Adj[v].push_back(u);
	}
	bool flag = true;
	vector<int> odd;
	for (int i = 1; i <= n; i++) {
		cout << Adj[i].size();
		if (Adj[i].size() % 2 == 1) {
			flag = false;
			odd.push_back(i);
		}
		if (i < n) {
			cout << " ";
		} else {
			cout << endl;
		}
	}
	if (flag) {
		cout << "Eulerian" << endl;
	} else {
		if (odd.size() == 2) {
			st = odd[0];
			ed = odd[1];
			cout << "Semi-Eulerian" << endl;
		} else {
			cout << "Non-Eulerian" << endl;
		}
	}



	return 0;
}
