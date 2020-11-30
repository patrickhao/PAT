#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 1000;
int n = 10, heap[maxn];

void downAdjust(int low, int high) {
    int i = low, j = 2 * i;
    while (j <= high) {
        if (j + 1 <= high && heap[j + 1] > heap[j]) {
            j = j + 1;
        }
        if (heap[j] > heap[i]) {
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

void deleteTop() {
    heap[1] = heap[n--];
    downAdjust(1, n);
}

void upAdjust(int low, int high) {
    int i = high, j = i / 2;
    while (j >= low) {
        if (heap[j] < heap[i]) {
            i = j;
            j = i / 2;
        } else {
            break;
        }
    }
}

void insert(int v) {
    heap[++n] = v;
    upAdjust(1, n);
}

void heapSort() {
    createHeap();
    for (int i = n; i > 1; i--) {
        swap(heap[1], heap[i]);
        downAdjust(1, i - 1);
    }
}

int main() {
    return 0;
}
