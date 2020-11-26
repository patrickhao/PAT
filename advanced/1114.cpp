#include <cstdio>
#include <vector>
#include <queue>
#include <map>

using namespace std;
const int maxn = 1010;
struct node {
    vector<int> v;
    vector<int> a;
    int id, s;
} D[maxn];
int n;
bool vis[maxn] = {false};
map<int, int> idToIndex;

void dfs(int s) {
    vis[s] = true;
    for (int i = 0; i < D[s].v.size(); i++) {
        if (!vis[i]) {
            dfs(idToIndex[D[s].v[i]]);
        }
    }
}

int main() {
    freopen("./sample_in/1114.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &D[i].id);
        idToIndex[D[i].id] = i;
        int p, m;
        scanf("%d %d", &p, &m);
        if (p != -1) {
            D[i].v.push_back(p);
        }
        if (m != -1) {
            D[i].v.push_back(m);
        }
        int num;
        scanf("%d", &num);
        while (num--) {
            int cid;
            scanf("%d", &cid);
            D[i].v.push_back(cid);
        }
        scanf("%d", &D[i].s);
        for (int i = 0; i < D[i].s; i++) {
            int are;
            scanf("%d", &are);
            D[i].a.push_back(are);
        }
    }

    dfs(0);

    return 0;
}