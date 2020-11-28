#include <iostream>
#include <algorithm>

using namespace std;
const int maxn = 100010;

struct elem {
    int sn, area;

    elem() {
        sn = area = 0;
    }
} D[maxn];

struct ans {
    int id, m;
    double sn, area;

    ans() {
        id = m = 0;
        sn = area = 0.0;
    }
} Ans[maxn];

int father[maxn];
bool vis[maxn] = {false};

bool cmp(ans a1, ans a2) {
    if (a1.area != a2.area) {
        return a1.area > a2.area;
    } else {
        return a1.id < a2.id;
    }
}

void init() {
    for (int i = 0; i < maxn; i++) {
        father[i] = i;
    }
}

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

    if (fa > fb) {
        father[fa] = fb;
    } else if (fa < fb) {
        father[fb] = fa;
    }
}

int main() {
    freopen("./sample_in/1114.txt", "r", stdin);
    init();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int id, fid, mid, k, cid;
        cin >> id >> fid >> mid >> k;
        vis[id] = true;
        if (fid != -1) {
            vis[fid] = true;
            Union(id, fid);
        }
        if (mid != -1) {
            vis[mid] = true;
            Union(id, mid);
        }
        while (k--) {
            cin >> cid;
            vis[cid] = true;
            Union(id, cid);
        }
        cin >> D[id].sn >> D[id].area;
    }

    for (int i = 0; i < maxn; i++) {
        if (vis[i]) {
            Ans[findFather(i)].id = findFather(i);
            Ans[findFather(i)].sn += D[i].sn;
            Ans[findFather(i)].area += D[i].area;
            Ans[findFather(i)].m++;
        }
    }

    int fn = 0;
    for (int i = 0; i < maxn; i++) {
        if (Ans[i].id != 0) {
            fn++;
            Ans[i].sn /= Ans[i].m;
            Ans[i].area /= Ans[i].m;
        }
    }
    sort(Ans, Ans + maxn, cmp);
    cout << fn << endl;
    for (int i = 0; i < fn; i++) {
        printf("%04d %d %.3f %.3f\n", Ans[i].id, Ans[i].m, Ans[i].sn, Ans[i].area);
    }

    return 0;
}