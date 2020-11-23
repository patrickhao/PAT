#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;
const int maxn = 100010;

struct node {
    int address, data, next;
    int tag;

    node () {
        tag = 2 * maxn;
    }
} List[100010];

bool cmp(node n1, node n2) {
    return n1.tag < n2.tag;
}

int main() {
    freopen("./sample_in/1097.txt", "r", stdin);
    int begin, n;
    bool hashTable[maxn] = {false};
    scanf("%d %d", &begin, &n);
    while (n--) {
        int ad;
        scanf("%d", &ad);
        scanf("%d %d", &List[ad].data, &List[ad].next);
        List[ad].address = ad;
    }
    int p = begin;
    int n1 = 0, n2 = 0;
    while (p != -1) {
        int absv = abs(List[p].data);
        if (hashTable[absv]) {
            List[p].tag = maxn + n2++;
        } else {
            List[p].tag = n1++;
            hashTable[absv] = true;
        }
        p = List[p].next;
    }
    sort(List, List + maxn, cmp);
    
    for (int i = 0; i < n1 + n2; i++) {
        printf("%05d %d ", List[i].address, List[i].data);
        if (i == n1 -1 || i == n1 + n2 - 1) {
            printf("-1\n");
        } else {
            printf("%05d\n", List[i + 1].address);
        }
    }
    return 0;
}