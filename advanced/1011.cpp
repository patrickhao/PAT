#include <cstdio>

typedef struct {
    double w;
    double t;
    double l;
}game;

int main() {
    freopen("./sample_in/1011.txt", "r", stdin);
    game g[3];
    char final[3] = {0};
    double num[3] = {0.0};
    for(int i = 0; i < 3; i++) {
        scanf("%lf%lf%lf", &g[i].w, &g[i].t, &g[i].l);
        if(g[i].w >= g[i].t) {
            if(g[i].w >= g[i].l) {
                final[i] = 'W';
                num[i] = g[i].w;
            }
            else {
                final[i] = 'L';
                num[i] = g[i].l;
            }
        }
        else {
            if(g[i].t >= g[i].l) {
                final[i] = 'T';
                num[i] = g[i].t;
            }
            else {
                final[i] = 'L';
                num[i] = g[i].l;
            }
        }
    }
    
    for(int i = 0; i < 3; i++) {
        printf("%c ", final[i]);
    }
    printf("%.2f", (num[0] * num[1] * num[2] * 0.65 - 1) * 2);
    return 0;
}