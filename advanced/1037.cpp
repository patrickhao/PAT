#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

struct elem {
    long long v;
    bool flag;
} arr[100010], brr[100010];

int nc, np;
long long select1() {
    int MAX = 0, id = 0;
    for (int i = 0; i < nc; i++) {
        if (arr[i].flag && abs(arr[i].v) > abs(MAX)) {
            MAX = arr[i].v;
            id = i;
        }
    }
    arr[id].flag = false;
    return MAX;
}

long long select2(int flag) {
    if (flag == 0) {
        int MAX = -1, id = 0;
        for (int i = 0; i < np; i++) {
            if (brr[i].flag && brr[i].v > MAX) {
                MAX = brr[i].v;
                id = i;
            }
        }
        if (MAX == -1) {
            return 0;
        } else {
            brr[id].flag = false;
            return MAX;
        }
    } else {
        int MIN = 1, id = 0;
        for (int i = 0; i < np; i++) {
            if (brr[i].flag && brr[i].v < MIN) {
                MIN = brr[i].v;
                id = i;
            }
        }
        if (MIN == 1) {
            return 0;
        } else {
            brr[id].flag = false;
            return MIN;
        }
    }
}

int main() {
    freopen("./sample_in/1037.txt", "r", stdin);
    long long ans = 0;
    scanf("%d", &nc);
    for (int i = 0; i < nc; i++) {
        scanf("%lld", &arr[i].v);
        arr[i].flag = true;
    }
    scanf("%d", &np);
    for (int i = 0; i < np; i++) {
        scanf("%lld", &brr[i].v);
        brr[i].flag = true;
    }
    for (int i = 0; i < nc || i < np; i++) {
        long long t1 = select1();
        long long t2;
        if (t1 >= 0) {
            t2 = select2(0);
        } else {
            t2 = select2(1);
        }
        if (t2 == 0) {
            continue;
        } else {
            ans += (t1 * t2);
        }
    }
    printf("%d", ans);

    return 0;
}