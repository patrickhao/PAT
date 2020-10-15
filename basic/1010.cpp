#include <cstdio>

int main() {
    freopen("./sample_in/1010.txt", "r", stdin);
    int temp1, temp2, dataIn[1010] = {0}, dataOut[1010] = {0}, index = 0;
    //输入数据组数未知情况下的scanf
    while(true) {
        int s;
        s = scanf("%d%d", &temp1, &temp2);
        if(s == -1) {
            break;
        }
        dataIn[temp2] = temp1;
    }
    for(int i = 1; i < 1010; i++) {
        if(dataIn[i] != 0) {
            dataOut[i - 1] = i * dataIn[i];
        }
    }
    for(int i = 0; i < 1010; i++) {
        if(dataOut[i] != 0) {
            index = i;
            break;
        }
    }
    for(int i = 1009; i >= 0; i--) {
        if(i == index) {
            break;
        }
        if(dataOut[i] != 0) {
            printf("%d %d ", dataOut[i], i);
        }
    }
    printf("%d %d", dataOut[index], index);
    return 0;
}