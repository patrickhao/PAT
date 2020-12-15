#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;
bool hashTable[maxn] = {false};
int table[maxn];

bool isPrime(int n) {
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	freopen("./sample_in/1145.txt", "r", stdin);
	int size, n, m;
	scanf("%d %d %d", &size, &n, &m);
	while (!isPrime(size)) {
		size++;
	}
	//insert
	for (int i = 0; i < n; i++) {
		int temp, j;
		scanf("%d", &temp);
		for (j = 0; j < size; j++) {
			if (!hashTable[(temp + j * j) % size]) {
				hashTable[(temp + j * j) % size] = true;
				table[(temp + j * j) % size] = temp; 
				break;
			}
		}		
		if (j == size) {
			printf("%d cannot be inserted.\n", temp);
		}
	}
	//search
	int ans = 0;
	for (int i = 0; i < m; i++) {
		int temp, j;
		scanf("%d", &temp);
		for (j = 0; j <= size; j++) {
			ans++;
			if (!hashTable[(temp + j * j) % size] || table[(temp + j * j) % size] == temp) {
				break;
			}
		}
	}

	printf("%.1f\n", ans * 1.0 / m);
	return 0;
}
