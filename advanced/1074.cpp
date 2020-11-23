#include <cstdio>
#include <algorithm>

using namespace std;
const int maxn = 100010;

struct node {
    int address, data, next;
    int tag;
} List[maxn];

bool cmp(node n1, node n2) {
    return n1.tag < n2.tag;
}

int main() {
    freopen("./sample_in/1074.txt", "r", stdin);
    for (int i = 0; i < maxn; i++) {
        List[i].tag = maxn;
    }
    int head, n, k;
    scanf("%d %d %d", &head, &n, &k);
    for (int i = 0; i < n; i++) {
        int ad;
        scanf("%d", &ad);
        scanf("%d %d", &List[ad].data, &List[ad].next);
        List[ad].address = ad;
    }
    int cur = head, count = 0;
    while (cur != -1) {
        List[cur].tag = count++;
        cur = List[cur].next;
    }
    sort(List, List + maxn, cmp);
    n = count;

    for (int i = 0; i < n / k; i++) {
        for (int j = (i + 1) * k - 1; j > i * k; j--) {
            printf("%05d %d %05d\n", List[j].address, List[j].data, List[j - 1].address);
        }
        printf("%05d %d ", List[i * k].address, List[i * k].data);
        if (i < n / k - 1) {
            printf("%05d\n", List[(i + 2) * k - 1].address);
        } else {
            if (n % k == 0) {
                printf("-1\n");
            } else {
                printf("%05d\n", List[(i + 1) * k].address);
                for (int j = n / k * k; j < n; j++) {
                    printf("%05d %d ", List[j].address, List[j].data);
                    if (j < n - 1) {
                        printf("%05d\n", List[j + 1].address);
                    } else {
                        printf("-1\n");
                    }
                }
            }
        }
    }

    return 0;
}