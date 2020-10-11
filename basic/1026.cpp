#include <cstdio>
#include <cmath>

const int CLK_TCK = 100;

int main() {
    freopen("./sample_in/1026.txt", "r", stdin);
    int time1, time2, tSec, h, m, s;
    scanf("%d%d", &time1, &time2);
    tSec = round((double)(time2 - time1) / (double)CLK_TCK);
    s = tSec % 60;
    m = (tSec / 60) % 60;
    h = (tSec / 60) / 60;
    printf("%02d:%02d:%02d", h, m, s);
    return 0;
}