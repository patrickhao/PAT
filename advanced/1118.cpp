#include <iostream>

using namespace std;
const int maxn = 100010;
int father[maxn];
bool vis[maxn] = {false};

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
        father[a] = x;
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
    freopen("./sample_in/1118.txt", "r", stdin);
    init();
    int n;
    cin >> n;
    while (n--) {
        int k, fid, temp;
        cin >> k >> fid;
        vis[fid] = true;
        for (int i = 1; i < k; i++) {
            cin >> temp;
            Union(fid, temp);
            vis[temp] = true;
        }
    }

    int treeNum = 0, birdNum = 0;
    for (int i = 1; i < maxn; i++) {
        if (vis[i] && i == findFather(i)) {
            treeNum++;
        }
        if (vis[i]) {
            birdNum++;
        }
    }
    cout << treeNum << " " << birdNum << endl;

    cin >> n;
    while (n--) {
        int b1, b2;
        cin >> b1 >> b2;
        if (findFather(b1) == findFather(b2)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}