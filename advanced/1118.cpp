#include <cstdio>

using namespace std;
const int maxn = 100010;
int father[maxn];
bool vis[maxn] = {false};

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

void init() {
    for (int i = 0; i < maxn; i++) {
        father[i] = i;
    } 
}

int main() {
    freopen("./sample_in/1118.txt", "r", stdin);
    init();
    int n, maxBid = 0;
    scanf("%d", &n);
    while (n--) {
        int num, f;
        scanf("%d", &num);
        scanf("%d", &f); 
        if (f > maxBid) {
            maxBid = f;
        }
        vis[f] = true;
        num--;
        while (num--) {
            int temp;
            if (temp > maxBid) {
                maxBid = temp;
            }
            scanf("%d", &temp);
            if (vis[temp]) {
                int tempF = findFather(temp);
                Union(tempF, f);
            } else {
                vis[temp] = true;
                Union(f, temp);
            }
        }
    }
    int unum = 0;
    for (int i = 1; i <= maxBid; i++) {
        if (findFather(i) == i) {
            unum++;
        }
    }
    printf("%d %d\n", unum, maxBid);
    scanf("%d", &n);
    while (n--) {
        int b1, b2;
        scanf("%d %d", &b1, &b2);
        if (findFather(b1) == findFather(b2)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }

    return 0;
}