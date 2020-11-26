#include <cstdio>
#include <algorithm>

using namespace std;
const int ot = 8 * 60 * 60;
const int ct = 17 * 60 * 60;

struct elem {
    int at;
    int t;
} D[10010];

bool cmp(elem e1, elem e2) {
    return e1.at < e2.at;
}

int n, k;

int main() {
    freopen("./sample_in/1017.txt", "r", stdin);
    scanf("%d %d", &n, &k);
    int index = 0;
    while (n--) {
        int h, m, s, tl;
        scanf("%d:%d:%d %d", &h, &m, &s, &tl);
        if (h * 60 * 60 + m * 60 + s > ct) {
            continue;
        }
        D[index].at = h * 60 * 60 + m * 60 + s;
        D[index].t = tl <= 60 ? tl : 60;
        index++;
    }
    sort(D, D + index, cmp);

    int wt = 0;
    for (int i = 0; i < index; i++) {
        if (D[i].at < ot) {
            wt = wt + ot - D[i].at;
        }
    }

    int wi[110] = {0}, cur = 0;
    for (int i = ot; i <= ct; i++) {
        bool flag = false;
        for (int j = 0; j < k; j++) {
            if (wi[j] == 0 && D[cur].at <= i) {
                wi[j] = D[cur].t * 60;
                cur++;
                if (cur == index) {
                    flag = true;
                    break;
                }
            }
        } 
        for (int j = 0; j < k; j++) {
            if (wi[j] > 0) {
                wi[j]--;
            }
        }
        if (flag) {
            break;
        }
        for (int j = cur; j < index; j++) {
            if (D[j].at <= i) {
                wt++;
            }
        }
    }
    double wtm = wt / 60 + ((wt % 60) / 60.0);
    printf("%.1f", wtm / index);
    return 0;
}