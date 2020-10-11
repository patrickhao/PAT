#include <cstdio>

int whoWin(int a1, int a2, int b1, int b2) {
    int aw = 0, bw = 0;
    if(a2 == a1 + b1) {
        aw++;
    }
    if(b2 == a1 + b1) {
        bw++;
    }
    if(aw == bw) {
        return 0;
    }
    else if(aw > bw) {
        return 1;
    }
    else {
        return 2;
    }
}

int main() {
    freopen("./sample_in/1046.txt", "r", stdin);
    int num, ad = 0, bd = 0, a1, a2, b1, b2, r;
    scanf("%d", &num);
    for(int i = 0; i < num; i++) {
        scanf("%d%d%d%d", &a1, &a2, &b1, &b2);
        r = whoWin(a1, a2, b1, b2);
        if(r == 1) {
            bd++;
        }
        else if(r == 2) {
            ad++;
        }
    }
    printf("%d %d", ad, bd);
    return 0;
}