#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("./sample_in/1066.txt", "r", stdin);
	int m, n, a, b, g;
	scanf("%d %d %d %d %d", &m, &n, &a, &b, &g);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int temp;
			scanf("%d", &temp);
			if (temp >= a && temp <= b) {
				printf("%03d", g);
			} else {
				printf("%03d", temp);
			}
			if (j < n - 1) {
				printf(" ");
			} else {
				printf("\n");
			}
		}
	}
	return 0;
}
