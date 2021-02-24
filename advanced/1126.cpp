#include <bits/stdc++.h>
using namespace std;
const int MAXN = 550;
int n, m;
bool G[MAXN][MAXN] = {false};
bool vis[MAXN] = {false};
int degree[MAXN] = {0};


void bfs(int i) {
	queue<int> q;
	vis[i] = true;
	q.push(i);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int v = 1; v <= n; v++) {
			if (vis[v] == false && G[u][v]) {
				q.push(v);
				vis[v] = true;
			}
		}
	}
}

int bfsTrave() {
	int ret = 0;
	for (int i = 1; i <= n; i++) {
		if (vis[i] == false) {
			bfs(i);
			ret++;
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	while (m--) {
		int u, v; cin >> u >> v;
		degree[u]++; degree[v]++;
		G[u][v] = true; G[v][u] = true;
	}

	int a = 0, b = 0;
	for (int i = 1; i <= n; i++) {
		if (degree[i] & 1) a++;
		else b++;
		cout << degree[i];
		cout << (i < n ? " " : "\n");
	}

	int cnt = bfsTrave();
	if (a == 0 && cnt == 1) cout << "Eulerian" << endl;
	else if (a == 2 && cnt == 1) cout << "Semi-Eulerian" << endl;
	else cout << "Non-Eulerian" << endl;
	return 0;
}