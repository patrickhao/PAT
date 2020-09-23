#include <cstdio>
#include <algorithm>
#include <cstdlib>

using namespace std;

typedef struct {
    double stock, totalPrice, price;
} mooncake;
//另一种解法，mooncake只使用了一次，可以不用typedef，精简代码
//struct mooncake{
//    double stock, totalPrice, price;
//} mData[1010];

bool cmp(mooncake a, mooncake b) {
    return a.price > b.price;
}

int main() {
    freopen("./sample_in/1020.txt", "r", stdin);
    int N, maxD;//最好将maxD声明为double，防止比较时出错
    double income = 0;
    scanf("%d %d", &N, &maxD);
    //除了声明动态数组，也可以将mData声明为较大整数（远大于题目要求），控制循环条件来控制数组的相对大小
    mooncake *mData = (mooncake*)malloc(N * sizeof(mooncake));
    for(int i = 0; i < N; i++) {
        scanf("%lf", &mData[i].stock);
    }
    for(int i = 0; i < N; i++) {
        scanf("%lf", &mData[i].totalPrice);
        mData[i].price = mData[i].totalPrice / mData[i].stock;
    }
    sort(mData, mData + N, cmp);
    for(int i = 0; i < N; i++) {
        //只遍历了一遍，元素不会被重复访问，可以删去mData[i].stocl > 0和mData[i].stock = 0来精简代码
        if(mData[i].stock <= maxD && mData[i].stock > 0) {
            income += mData[i].totalPrice; 
            maxD -= mData[i].stock;
            mData[i].stock = 0;
        } 
        else if(mData[i].stock > maxD && mData[i].stock > 0) {
            income += mData[i].price * maxD;
            maxD = 0;
            mData[i].stock -= maxD;
            break;
        }
        else {
            continue;
        }
    }
    printf("%.2f", income);
    return 0;
}