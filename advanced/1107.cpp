#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int n, father[maxn], arr[maxn] = {0}, user[maxn] = {0};

bool cmp(int a, int b) {
	return a > b;
}

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
	freopen("./sample_in/1107.txt", "r", stdin);
	init();
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int k, fid, tid;
		scanf("%d: %d", &k, &fid);
		k--;
		user[i] = fid;
		while (k--) {
			scanf("%d", &tid);
			Union(fid, tid);	
		}
	}
	for (int i = 1; i < maxn; i++) {
		arr[findFather(user[i])]++;
	}
	vector<int> v;
	for (int i = 1; i < maxn; i++) {
		if (arr[i] != 0) {
			v.push_back(arr[i]);
		}
	}
	sort(v.begin(), v.end(), cmp);
	printf("%d\n", v.size());
	for (int i = 0; i < v.size(); i++) {
		printf("%d", v[i]);
		if (i < v.size() - 1) {
			printf(" ");
		} else {
			printf("\n");
		}
	}

	return 0;
}
