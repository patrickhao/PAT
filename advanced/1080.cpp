#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

struct elem {
    int ge, gi, c[5], r, id, s;
    double ga;
} d[40010];
int quota[110];

bool cmp(elem e1, elem e2) {
    if(e1.ga != e2.ga) {
        return e1.ga > e2.ga;
    } else {
        return e1.ge > e2.ge;
    }
}

int main() {
    freopen("./sample_in/1080.txt", "r", stdin);
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 0; i < m; i++) {
        scanf("%d", quota + i);
    }
    for(int i = 0; i < n; i++) {
        d[i].id = i;
        scanf("%d %d", &d[i].ge, &d[i].gi);
        d[i].ga = (d[i].ge + d[i].gi) / 2.0;
        for(int j = 0; j < k; j++) {
            scanf("%d", &d[i].c[j]);
        }
    }

    sort(d, d + n, cmp);
    int rank = 1;
    d[0].r = 1;
    for(int i = 1; i < n; i++) {
        if(d[i].ga < d[i - 1].ga) {
            d[i].r = i + 1;
            rank = i + 1;
        } else {
            if(d[i].ge == d[i - 1].ge) {
                d[i].r = rank;
            } else {
                d[i].r = i + 1;
            }
        }
    }
    set<int> ans[110];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < k; j++) {
            int ss = d[i].c[j];
            if(quota[ss] > 0) {
                ans[ss].insert(d[i].id);
                quota[ss]--;
                d[i].s = ss;
                break;
            } else {
                if(i != 0 && d[i].r == d[i - 1].r && d[i - 1].s == ss) {
                    ans[ss].insert(d[i].id);
                    quota[ss]--;
                    d[i].s = ss;
                    break;
                }
            }
        }
    }
    for(int i = 0; i < m; i++) {
        if(ans[i].size() == 0) {
            printf("\n");
        } else {
            int count = 1;
            for(auto it = ans[i].begin(); it != ans[i].end(); it++) {
                printf("%d", *it);
                if(count++ < ans[i].size()) {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }

    return 0;
}