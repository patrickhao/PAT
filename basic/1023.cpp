#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main() {
    freopen("./sample_in/1023.txt", "r", stdin);
    int num[10];
    int x = 0;
    for(int i = 0; i < 10; i++) {
        scanf("%d", num + i);
        x += num[i];
    }
    int *outNum = (int*)malloc(x * sizeof(int));
    for(int i = 1; i < 10; i++) {
        if(num[i] > 0) {
            outNum[0] = i;
            num[i]--;
            break;
        }
    }
    for(int i = 1; i < x; i++) {
        for(int j = 0; j < 10; j++) {
            if(num[j] > 0) {
                outNum[i] = j;
                num[j]--;
                break;
            }
        }
    }
    for(int i = 0; i < x; i++) {
        printf("%d", outNum[i]);
    }
    //不要开没必要的数组浪费空间且使代码显得繁杂，更优解法
    //for(int i = 1; i < 10; i++) {
    //    if(num[i] > 0) {
    //        printf("%d", i);
    //        num[i]--;
    //        break;
    //    }
    //}
    //for(int i = 0; i < 10; i++) {
    //    for(int j = 0; j < num[i]; j++) {
    //        printf("%d", i);
    //    }
    //}
    return 0; 
}