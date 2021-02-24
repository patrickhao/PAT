#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;
int father[MAXN];
bool hashTable[MAXN] = {false};

struct elem {
    int m, a;
} D[MAXN];

struct elem2 {
    int id, m, s, a;
    double as, aa;
} DD[MAXN];

bool cmp(elem2 a, elem2 b) {
    if (a.aa != b.aa) return a.aa > b.aa;
    else return a.id < b.id;
}

int findFather(int a) {
    int x = a;
    while (x != father[x]) x = father[x];
    while (a != x) {
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}

void Union(int a, int b) {
    int fa = findFather(a);
    int fb = findFather(b);
    if (fa != fb) father[fa] = fb;
}

int main() {
    for (int i = 0; i < MAXN; i++) father[i] = i;
    int n; cin >> n;
    while (n--) {
        int id, f, m, k;
        cin >> id >> f >> m >> k;
        hashTable[id] = true;
        if (f != -1) Union(f, id), hashTable[f] = true;
        if (m != -1) Union(m, id), hashTable[m] = true;
        for (int i = 0; i < k; i++) {
            int temp; cin >> temp;
            hashTable[temp] = true;
            Union(id, temp);
        }
        elem e;
        cin >> e.m >> e.a;
        D[id] = e;
    }

    int cnt = 0;
    map<int, int> mp;
    for (int i = 0; i < MAXN; i++) {
        if (hashTable[i] && father[i] == i) {
            mp[i] = cnt;
            cnt++;
        }
    }

    for (int i = 0; i < cnt; i++) {
        DD[i].id = -1;
        DD[i].m = DD[i].s = DD[i].a = 0;
    }

    for (int i = 0; i < MAXN; i++) {
        if (hashTable[i]) {
            int curf = findFather(i);
            int ind = mp[curf];
            if (DD[ind].id == -1) DD[ind].id = i;
            DD[ind].m++;
            DD[ind].s += D[i].m;
            DD[ind].a += D[i].a;
        }
    }

    for (int i = 0; i < cnt; i++) {
        DD[i].as = DD[i].s * 1.0 / DD[i].m;
        DD[i].aa = DD[i].a * 1.0 / DD[i].m;
    }
    sort(DD, DD + cnt, cmp);
    
    cout << cnt << endl;
    for (int i = 0; i < cnt; i++) {
        printf("%04d %d %.3f %.3f\n", DD[i].id, DD[i].m, DD[i].as, DD[i].aa);
    }

    return 0;
}