#include <cstdio>
int binarySearch(int A[], int left, int right, int x) {
    int mid;
    while(left <= right) {
        mid = (left + right) / 2;
        if(A[mid] == x) {
            return mid;
        }
        else if(A[mid] > x) {
            right = mid - 1;
        }
        else if(A[mid] < x) {
            left = mid + 1;
        }
        
    }
    return -1;
}

int main() {  
    const int n = 10;
    int A[n] =  {0, 1, 2, 3, 4, 5, 6, 7};
    printf("%d\n", binarySearch(A, 0, n-1, 5));
    return 0;
}