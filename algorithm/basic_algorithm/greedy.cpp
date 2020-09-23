#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 110;

struct Inteval {
    int x;
    int y;
}I[maxn];

bool cmp(Inteval m, Inteval n) {
    if(m.x != n.x) {
        return m.x > n.x;
    }
    else {
        return m.y < n.y;
    }
}
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &I[i].x, &I[i].y);
    } 
    sort(I, I + n, cmp);
    int num = 1, preX = I[0].x;
    for(int i = 1 ; i < n; i++) {
        if(I[i].y <= preX) {
            preX = I[i].x;
            num ++;
        }
    }
    printf("%d\n", num);

    return 0;
}
