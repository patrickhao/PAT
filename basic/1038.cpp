#include <cstdio>

int main() {
    freopen("./sample_in/1038.txt", "r", stdin);
    int n, k, temp, hashTable[110] = {0};
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &temp);
        hashTable[temp]++;
    }
    scanf("%d", &k);
    for(int i = 0; i < k; i++) {
        scanf("%d", &temp);
        printf("%d", hashTable[temp]);
        if(i < k - 1) {
            printf(" ");
        }
    }
    return 0;
}