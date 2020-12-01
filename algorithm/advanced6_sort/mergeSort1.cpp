#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &a, int L1, int R1, int L2, int R2) {
	int i = L1, j = L2;
	vector<int> temp;
	while (i <= R1 && j <= R2) {
		if (a[i] < a[j]) {
			temp.push_back(a[i++]);
		} else {
			temp.push_back(a[j++]);
		}
	}
	while (i <= R1) {
		temp.push_back(a[i++]);
	}
	while (j <= R2) {
		temp.push_back(a[j++]);
	}
	for (int i = 0; i < temp.size(); i++) {
		a[L1 + i] = temp[i];
	}
}

void mergeSort(vector<int> &a, int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		mergeSort(a, left, mid);
		mergeSort(a, mid + 1, right);
		merge(a, left, mid, mid + 1, right);
	}
}

int main() {
	vector<int> a = {3, 2, 5, 1, 4};
	for (int i : a) {
		cout << i << " ";
	}	
	cout << endl;
	mergeSort(a, 0, a.size() - 1);
	for (int i : a) {
		cout << i << " ";
	}	
	cout << endl;
	return 0;
}
