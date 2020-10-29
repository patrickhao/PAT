#include <cstdio>
#include <cstdlib>

int main() {
    freopen("./sample_in/1007.txt", "r", stdin);
    int k, a, b, sumNow, sumMax = 0, len = 0;
    scanf("%d", &k);
    int* arr = (int*)malloc(k * sizeof(int));
    for(int i = 0; i < k; i++) {
        scanf("%d", arr + i);
    } 
    a = arr[0];
    b = arr[k - 1];
    for(int i = 0; i < k; i++) {
        sumNow += arr[i];
        if(sumNow < 0) {
            sumNow = 0;
            len = 0;
        }
        else {
            len++;
            if(sumNow > sumMax) {
                b = arr[i];
            }
        }
    }

    return 0;
}