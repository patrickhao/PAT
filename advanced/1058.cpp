#include <cstdio>

int main() {
    freopen("./sample_in/1058.txt", "r", stdin);
    int g, s, k, temp1, temp2, temp3;
    scanf("%d.%d.%d %d.%d.%d", &g, &s, &k, &temp1, &temp2, &temp3);
    g += temp1;
    s += temp2;
    k += temp3;
    s += (k / 29);
    k = k - ((k / 29) * 29);
    g += (s / 17);
    s = s - ((s / 17) * 17);
    printf("%d.%d.%d", g, s, k);
    return 0;
}