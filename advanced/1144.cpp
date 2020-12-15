#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("./sample_in/1144.txt", "r", stdin);
	int n;
	map<int, int> mp;
	scanf("%d", &n);
	while (n--) {
		int temp;
		scanf("%d", &temp);
		mp[temp] = 1;
	}
	int num = 0;
	while (++num) {
		if (mp[num] == 0) {
			printf("%d\n", num);
			break;
		}
	}

	return 0;
}
