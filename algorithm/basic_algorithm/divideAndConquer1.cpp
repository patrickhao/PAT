/*
1-n的全排列，改变for中的i可以改变起始点x，输出x-n全排列
*/
#include <cstdio>

const int maxn = 11;
int n, P[maxn], hashTable[maxn] = {false};

void generateP(int index) {
    if(index == n + 1) {
        for(int i = 1; i <= n; i++) {
            printf("%d ", P[i]);
        }
        printf("\n");
        return;
    }
    for(int i = 1; i <= n; i++) {
        if(hashTable[i] == false) {
            P[index] = i;
            hashTable[i] = true;
            generateP(index + 1);
            hashTable[i] = false;//只更改了一位，因此只需将以为重置
        }
    }
    //有一个隐藏的return，因为返回值是void，故隐藏了，for执行结束后return
    //梯形似的调用
    //return;
}

int main() {
    n = 6;
    generateP(1);
    return 0;
}