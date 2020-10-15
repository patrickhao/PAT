#include <cstdio>
#include <cstdlib>

//超时间复杂度，想办法去掉不必要的循环，充分利用必须的循环做数据处理，如数组读入时。
int sdist(int* dist, int num, int a1, int a2, int sum) {
    int sum1, sum2, temp;
    if(a1 > a2) {
        temp = a1;
        a1 = a2;
        a2 = temp;
    }
    sum1 = dist[a2 - 1] - dist[a1 - 1];
    sum2 = sum - sum1;
    return sum1 < sum2 ? sum1 : sum2;
}

int main() {
    freopen("./sample_in/1046.txt", "r", stdin);
    int num, m, temp1, temp2, sum = 0;
    scanf("%d", &num);
    int* dist = (int*)malloc(num * sizeof(int));
    //数组未保存第一位和第N位之间的距离
    for(int i = 0; i < num; i++) {
        scanf("%d", &temp1);
        dist[i] = sum;
        sum += temp1;
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        scanf("%d%d", &temp1, &temp2);
        printf("%d\n", sdist(dist, num, temp1, temp2, sum));
    }
    return 0;
}