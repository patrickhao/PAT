#include <bits/stdc++.h>
using namespace std;

void mergeSort(int a[], int n) {
	for (int step = 2; step / 2 < n; step *= 2) {
		for (int i = 0; i < n; i += step) {
			sort(a + i, a + min(i + step, n));
		}
	}
}

int main() {
	int a[8] = {5, 2, 3, 4, 1, 12, 4, 9};
	for (int i : a) {
		cout << i << " ";
	}	
	cout << endl;
	mergeSort(a, 8);
	for (int i : a) {
		cout << i << " ";
	}	
	cout << endl;
	return 0;
}
