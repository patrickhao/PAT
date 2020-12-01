#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &a) {
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < a.size() - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]);
			}
		}
	}
}

int main() {
	vector<int> a = {3, 2, 5, 1, 4};
	for (int i : a) {
		cout << i << " ";
	}	
	cout << endl;
	bubbleSort(a);
	for (int i : a) {
		cout << i << " ";
	}	
	cout << endl;
	return 0;
}
