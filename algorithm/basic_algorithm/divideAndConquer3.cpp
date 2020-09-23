#include <cstdio>
#include <cmath>

const int maxn = 11;
int n, count = 0, P[maxn], hashTable[maxn] = {false};

void generateP(int index) {
    if(index == n + 1) {
        count++;
        return;
    }
    for(int i = 1; i <= n; i++) {
        if(hashTable[i] == false){
            bool flag = true;
            for(int pre = 1; pre < index; pre++) {
                if(abs(P[pre] - i) == abs(pre - index)) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                P[index] = i;
                hashTable[i] = true;
                generateP(index + 1);
                hashTable[i] = false;
            }
        }
    }
}

int main() {
    n = 5;
    generateP(1);
    printf("%d\n", count);
    return 0;
}