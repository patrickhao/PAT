#include <cstdio>

int main() {
    freopen("./sample_in/1021.txt", "r", stdin);
    int index = 0, hashTable[10] = {0};
    char num[1010] = {0};
    scanf("%s", num);
    while(num[index]) {
        hashTable[num[index] - '0']++;
        index++;
    }
    for(int i = 0; i < 10; i++) {
        if(hashTable[i]) {
            printf("%d:%d\n", i, hashTable[i]);
        }
    }
    
    return 0;
}