#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 110;
int n, heap[maxn], arr[maxn], brr[maxn];

void showArr(int a[]) {
	for (int i = 0; i < n; i++) {
		printf("%d", a[i]);
		if (i < n - 1) {
			printf(" ");
		} else {
			printf("\n");
		}
	}
}

bool judge(int a[], int b[]) {
	for (int i = 0; i < n; i++) {
		if (a[i] != b[i]) {
			return false;
		}
	}
	return true;
}

bool insertSort() {
	int tag = false;
	for (int i = 1; i < n; i++) {
		int temp = arr[i], j = i;
		while (j > 0 && arr[j - 1] > temp) {
			arr[j] = arr[j - 1]; 
			j--;
		}
		arr[j] = temp;
		if (tag) {
			break;
		}
		if (judge(arr, brr)) {
			tag = true;
		}
	}
	return tag;
}

void downAdjust(int l, int r) {
	int i = l, j = 2 * i;
	while (j <= r) {
		if (j + 1 <= r && heap[j + 1] > heap[j]) {
			j = j + 1;
		}
		if (heap[j] > heap[i]) {
			swap(heap[j], heap[i]);
			i = j;
			j = 2 * i;
		} else {
			break;
		}
	}
}

void createHeap() {
	for (int i = n / 2; i > 0; i--) {
		downAdjust(i, n);
	}
}

void heapSort() {
	int tag = false;
	createHeap();
	for (int i = n; i > 1; i--) {
		swap(heap[i], heap[1]);
		downAdjust(1, i - 1);
		if (tag) {
			break;
		}
		if (judge(heap + 1, brr)) {
			tag = true;
		}
 	}	
}


int main() {
    freopen("./sample_in/1098.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", arr + i);
		heap[i + 1] = arr[i];
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", brr + i);
	}
	if (insertSort()) {
		printf("Insertion Sort\n");
		showArr(arr);
	} else {
		heapSort();
		printf("Heap Sort\n");
		showArr(heap + 1);
	}
    return 0;
}
