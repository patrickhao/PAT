#include <cstdio>
#include <algorithm>

using namespace std;

struct mooncake {
    double num, p;
} Data[1010];

bool cmp(mooncake m1, mooncake m2) {
    return m1.p > m2.p;
}

int main() {
    freopen("./sample_in/1070.txt", "r", stdin);
    int n;
    double d;
    scanf("%d %lf", &n, &d);
    for(int i = 0; i < n; i++) {
        scanf("%lf", &Data[i].num);
    }
    for(int i = 0; i < n; i++) {
        scanf("%lf", &Data[i].p);
        Data[i].p /= Data[i].num;
    }
    sort(Data, Data + n, cmp);

    double profit = 0.0, curD = 0.0;
    for(int i = 0; i < n; i++) {
        if((d - curD) >= Data[i].num) {
            profit += (Data[i].num * Data[i].p);
            curD += Data[i].num;
            continue;
        } else if((d - curD) < Data[i].num && (d - curD) > 0) {
            profit += ((d - curD) * Data[i].p);
            curD = d;
            break;
        }
    }
    printf("%.2f", profit);

    return 0;
}