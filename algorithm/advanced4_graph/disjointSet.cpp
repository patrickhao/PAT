//并查集判断图是否有环
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000;
int n, father[maxn];

void init() {
	for (int i = 0; i < maxn; i++) {
		father[i] = i;
	}
}

int findFather(int x) {
	int a = x;
	while (x != father[x]) {
		x = father[x];
	}

	//路径压缩
	while (a != father[a]) {
		int z = a;
		a = father[a];
		father[z] = x;
	}
	return x;
}

void Union(int a, int b) {
	int fa = findFather(a);
	int fb = findFather(b);

	if (fa != fb) {
		father[fa] = fb;
	}
}

int main() {
	init();
	n = 5;
	int graph[5][2] = {
		{1, 2}, {2, 4}, {4, 5}, {5, 3}, {3, 1}
	};
	bool flag = false;
	for (int i = 0; i < n; i++) {
		int x = graph[i][0];
		int y = graph[i][1];
		if (findFather(x) == findFather(y)) {
			flag = true;
			break;
		}
		Union(x, y);
	}
	if (flag) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	return 0;
}
