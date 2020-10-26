#include <cstdio>
#include <algorithm>

using namespace std;

typedef struct {
    int id, vg, tg;
} people;

bool cmp(people p1, people p2) {
    if((p1.vg + p1.tg) != (p2.vg + p2.tg)) {
        return (p1.vg + p1.tg) > (p2.vg + p2.tg);
    }
    else {
        if(p1.vg != p2.vg) {
            return p1.vg > p2.vg;
        }
        else {
            return p1.id < p2.id;
        }
    }
}

int main() {
    freopen("./sample_in/1015.txt", "r", stdin);
    people temp, data[4][100010];
    int n, min, max, index[4] = {0};
    scanf("%d %d %d", &n, &min, &max);
    while(n--) {
        scanf("%d %d %d", &temp.id, &temp.vg, &temp.tg);
        if((temp.vg >= min) && (temp.tg >= min)) {
            if((temp.vg >= max) && (temp.tg >= max)) {
                data[0][index[0]++] = temp;
            }
            else if((temp.vg >= max) && (temp.tg < max)) {
                data[1][index[1]++] = temp;
            }
            else if((temp.vg < max) && (temp.tg < max) && (temp.vg >= temp.tg)) {
                data[2][index[2]++] = temp;
            }
            else {
                data[3][index[3]++] = temp;
            }
        }
    }
    printf("%d\n", index[0] + index[1] + index[2] + index[3]);
    for(int i = 0; i < 4; i++) {
        if(index[i] > 0) {
            sort(data[i], data[i] + index[i], cmp);
            for(int j = 0; j < index[i]; j++) {
                printf("%d %d %d\n",data[i][j].id, data[i][j].vg, data[i][j].tg);
            }
        }
    }

    return 0;
}