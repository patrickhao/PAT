#include <cstdio>

int main() {
    freopen("./sample_in/1047.txt", "r", stdin);
    int n, t1, t2, t3, hashTable[1010] = {0};
    scanf("%d", &n);
    while(n--) {
        scanf("%d-%d %d", &t1, &t2, &t3);
        hashTable[t1] += t3;
    }
    int m = 0, index = 0;
    for(int i = 0; i < 1010; i++) {
        if(hashTable[i] > m) {
            m = hashTable[i];
            index = i;
        }
    }
    printf("%d %d", index, m);

    return 0;
}