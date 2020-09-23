#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    freopen("./sample_in/1005.txt", "r", stdin);
    //不确定数组大小时，尽量开大点
    int hashTable[100000] = {0}, input[100], output[100];
    int k, n, outNum = 0;
    scanf("%d", &k);
    for(int i = 0; i < k; i++) {
        scanf("%d", &n);
        input[i] = n;
        while (n != 1) {
            hashTable[n]++;
            if (n % 2 == 1) {
                n = (3 * n + 1) / 2;
            } 
            else {
                n = n / 2;
            }
        }       
    }
    sort(input, input + k);
    for(int i = k - 1; i >= 0; i--) {
        int elem = input[i];
        if(hashTable[elem] == 1) {
            output[outNum++] = elem;
        }
    }
    for(int i = 0; i < outNum - 1; i++) {
        printf("%d ", output[i]);
    }
    printf("%d", output[outNum - 1]);
    return 0;
}