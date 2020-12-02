#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int maxn = 110;
int n, arr[maxn], brr[maxn], crr[maxn];

bool judge(int a[], int b[]) {
	for (int i = 0; i < n; i++) {
		if (a[i] != b[i]) {
			return false;
		}
	}
	return true;
}

bool insertSort() {
	bool tag = false;
	for (int i = 1; i < n; i++) {
		int j = i, temp = arr[i];
		while (j > 0 && arr[j - 1] > temp) {
			arr[j] = arr[j - 1];
			j--;
		}
		arr[j] = temp;
		if (tag){
			break;
		}
		if (judge(arr, brr)) {
			tag = true;
		}
	}
	return tag ? true : false;
}

void mergeSort() {
	bool tag = false;
	for (int step = 2; step / 2 < n; step += 2) {
		for (int i = 0; i < n; i += step) {
			sort(crr + i, crr + min(step + i, n));
		}
		if (tag) {
			break;
		}
		if (judge(crr, brr)) {
			tag = true;
		}
	}
}

int main() {
    freopen("./sample_in/1089.txt", "r", stdin);
	scanf("%d", &n);
    for (int i = 0; i < n; i++) {
		scanf("%d", arr + i);
		crr[i] = arr[i];
    }
    for (int i = 0; i < n; i++) {
		scanf("%d", brr + i);
    }
	bool tag = insertSort();
	if (tag) {
		printf("Insertion Sort\n");
		for (int i = 0; i < n; i++) {
			printf("%d", arr[i]);
			if (i < n - 1) {
				printf(" ");
			} else {
				printf("\n");
			}
		}
	} else {
		mergeSort();
		printf("Merge Sort\n");
		for (int i = 0; i < n; i++) {
			printf("%d", crr[i]);
			if (i < n - 1) {
				printf(" ");
			} else {
				printf("\n");
			}
		}
	}



    return 0;
}
