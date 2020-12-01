#include <bits/stdc++.h>
using namespace std;

void selectSort(vector<int> &a) {
	for (int i = 0; i < a.size(); i++) {
		int k = i;
		for (int j = i; j < a.size(); j++) {
			if (a[j] < a[k]) {
				k = j;
			}
		}
		swap(a[i], a[k]);
	}
}

int main() {
	vector<int> a = {3, 2, 5, 1, 4};
	for (int i : a) {
		cout << i << " ";
	}	
	cout << endl;
	selectSort(a);
	for (int i : a) {
		cout << i << " ";
	}	
	cout << endl;
	return 0;
}
