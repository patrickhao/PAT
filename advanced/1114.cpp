#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;
const int maxn = 100010;
struct node {
    int s, a;
} D[maxn];
int father[maxn];

int findFather(int x) {
    int a = x;
    while (x != father[x]) {
        x = father[x];
    }

    while (a != father[a]) {
        int z = a;
        a = father[a];
        father[z] = x;
    } 
    return x;
}

void Union(int a, int b) {
    int fa = findFather(a);
    int fb = findFather(b);
    if (fa != fb) {
        father[fa] = fb;
    }
}


int main() {
    freopen("./sample_in/1114.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int n1, n2, n3;
        scanf("%d %d %d", &n1, &n2, &n3);
        Union(n1, n2);
        Union(n1, n3);
        int num;
        scanf("%d", &num);
        while (num--) {
            int c;
            scanf("%d", &c);
            Union(n1, c);
        }
        scanf("%d %d", &D[n1].s, &D[n1].a);
    }
    int count = 0;
    for (int i = 0; i < maxn; i++) {
        if (father[i] = i) {
            count++;
        }
    }
    printf("%d", count);

    return 0;
}