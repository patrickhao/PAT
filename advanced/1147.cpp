#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int heap[maxn];
int m, n;

int on = 0;
void postOrder(int cur) {
	if (cur > n) {
		return;
	}
	postOrder(cur * 2);
	postOrder(cur * 2 + 1);
	printf("%d", heap[cur]);
	if (++on < n) {
		printf(" ");
	} else {
		printf("\n");
	}
}

bool minJudge(int cur) {
	int L = cur * 2, R = cur * 2 + 1;
	if (L <= n) {
		if (heap[L] < heap[cur]) {
			return false;
		} else {
			return minJudge(L);
		}
	}
	if (R <= n) {
		if (heap[R] < heap[cur]) {
			return false;
		} else {
			return minJudge(R);
		}
	}
	return true;
}

bool maxJudge(int cur) {
	int L = cur * 2, R = cur * 2 + 1;
	if (L <= n) {
		if (heap[L] > heap[cur]) {
			return false;
		} else {
			return maxJudge(L);
		}
	}
	if (R <= n) {
		if (heap[R] > heap[cur]) {
			return false;
		} else {
			return maxJudge(R);
		}
	}
	return true;
}

int main() {
	freopen("./sample_in/1147.txt", "r", stdin);
	scanf("%d %d", &m, &n);
	while (m--) {
		for (int i = 1; i <= n; i++) {
			scanf("%d", heap + i);
		}
		bool tag = true;
		if (minJudge(1)) {
			printf("Min Heap\n");
			tag = false;
		}
		if (maxJudge(1)) {
			printf("Max Heap\n");
			tag = false;
		}
		if (tag) {
			printf("Not Heap\n");
		}
		on = 0;
		postOrder(1);
	}

	return 0;
}
