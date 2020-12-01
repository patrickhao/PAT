#include <bits/stdc++.h>
using namespace std;

void insertSort(vector<int> &a) {
	for (int i = 1; i < a.size(); i++) {
		int temp = a[i], j = i;
		while (j > 0 && a[j - 1] > temp) {
			a[j] = a[j - 1];
			j--;
		}
		a[j] = temp;
	}	
}

int main() {
	vector<int> a = {3, 2, 5, 1, 4};
	for (int i : a) {
		cout << i << " ";
	}	
	cout << endl;
	insertSort(a);
	for (int i : a) {
		cout << i << " ";
	}	
	cout << endl;
	return 0;
}
