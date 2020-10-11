#include <cstdio>
#include <cstdlib>
//move每次移动一串数字，奇数位数组只需移动一次即可，偶数位数组根据m的值需要移动若干次

void move(int* arr, int m, int n, int startPosition) {
    int index, temp;
    index = (startPosition + n - m) % n;
    temp = arr[index];
    while(index != startPosition) {
        arr[index] = arr[(index + n - m) % n];
        index = (index + n - m) % n;
    }
    arr[index] = temp;
}

int main() {
    freopen("./sample_in/1008.txt", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);
    m = m % n;
    int* arr = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }
    if(n % 2 == 0) {
        if(n % m != 0) {
            move(arr, m, n, 0);        
        }
        else {
            for(int i = 0; i < m; i++) {
                move(arr, m, n, i);
            }
        }
    }
    else {
        move(arr, m, n, 0);
    }
    for(int i = 0; i < n - 1; i++) {
        printf("%d ", arr[i]);
    }
    printf("%d", arr[n - 1]);
    return 0;
}