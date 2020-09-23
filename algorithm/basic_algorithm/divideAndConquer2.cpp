#include <cstdio>
#include <cmath>

const int maxn = 11;
int n, count = 0, P[maxn], hashTable[maxn] = {false};

void generateP(int index) {
    if(index == n + 1) {
        //检验该组排列是否可用
        bool flag = true;
        for(int i = 1; i <= n; i++) {
            for(int j = i + 1; j <= n; j++) {
                if(abs(P[i] - P[j]) == abs(i - j)) {
                    //该组中有一对不可用则改组不可用
                    flag = false;
                }
            }
        }
        if(flag) {
            count++;
        }       
        return;
    }
    for(int i = 1; i <= n; i++) {
        if(hashTable[i] == false) {
            P[index] = i;
            hashTable[i] = true;
            generateP(index + 1);
            hashTable[i] = false;
        }
    }
}

int main() {
    n = 5;
    generateP(1);
    printf("%d\n", count);
    return 0;
}