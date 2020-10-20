#include <cstdio>
#include <algorithm>

using namespace std;

typedef struct {
    int g;
    int s;
    int k;
} money;

int main() {
    freopen("./sample_in/1037.txt", "r", stdin);
    money m1, m2, r;
    int all1, all2, flag = 1;
    scanf("%d.%d.%d %d.%d.%d", &m1.g, &m1.s, &m1.k, &m2.g, &m2.s, &m2.k);
    all1 = m1.g * 17 * 29 + m1.s * 29 + m1.k;
    all2 = m2.g * 17 * 29 + m2.s * 29 + m2.k;
    if(all1 > all2) {
        swap(all1, all2);
        flag = 0;
    }
    r.k = all2 - all1;
    r.s = r.k / 29;
    r.k = r.k % 29;
    r.g = r.s / 17;
    r.s = r.s % 17;
    if(flag) {
        printf("%d.%d.%d", r.g, r.s, r.k);
    }
    else {
        
        printf("-%d.%d.%d", r.g, r.s, r.k);
    }
    return 0;
}