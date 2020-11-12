#include <cstdio>

const int maxn = 5;
int n, v, maxValue = 0, ans = 0;
int w[maxn], c[maxn];

void dfs1(int index, int sumW, int sumC) {
    if(index == n) {
        if(sumW <= v && sumC > maxValue) {
            maxValue = sumC;
        }
        return;
    }

    dfs1(index + 1, sumW, sumC);
    dfs1(index + 1, sumW + w[index], sumC + c[index]);
}

//剪枝
void dfs2(int index, int sumW, int sumC) {
    if(index == n) {
        return;
    }

    dfs2(index + 1, sumW, sumC);
    if(sumW + w[index] <= v) {
        if(sumC + c[index] > ans) {
            ans = sumC + c[index];
        }
        dfs2(index + 1, sumW + w[index], sumC + c[index]);
    }
}

int main() {
    //data
    n = 5;
    v = 8;
    w[0] = 3;
    w[1] = 5;
    w[2] = 1;
    w[3] = 2;
    w[4] = 2;
    c[0] = 4;
    c[1] = 5;
    c[2] = 2;
    c[3] = 1;
    c[4] = 3;
    
    dfs1(0, 0, 0);
    printf("%d\n", maxValue);
    dfs2(0, 0, 0);
    printf("%d\n", ans);

    return 0;
}