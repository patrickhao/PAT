#include <cstdio>
const int maxn = 5;
bool hashTable[maxn] = {false};//全部初始化为false

int main() {
    int N[5] = {8, 3, 7, 6, 2}, M[3] = {7, 4, 2};
    for(int i = 0 ; i < 5; i++) {
        //可在读取N元素时直接设置hash，不用存储N值
        int elem = N[i];
        hashTable[elem] = true;
        //hashTable[elem]++可统计元素出现的个数
    }
    for(int i = 0; i < 3; i++) {
        int elem = M[i];
        if(hashTable[elem]) {
            printf("Yes\n");
        }
        else {
            printf("No\n");
        }
    }
    return 0;
}