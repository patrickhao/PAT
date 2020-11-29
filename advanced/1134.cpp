#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;
const int maxn = 10010;

struct node {
    int v;
    int id;

    node (int _v, int _id) : v(_v), id(_id) {}
};

int n, m;
vector<node> Adj[maxn];

int main() {
    freopen("./sample_in/1134.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        Adj[u].push_back(node(v, i));
        Adj[v].push_back(node(v, i));
    }
    int k;
    cin >> k;
    while (k--) {
        int num;
        cin >> num;
        set<int> s;
        for (int i = 0; i < num; i++) {
            int temp;
            cin >> temp;
            for (int i = 0; i < Adj[temp].size(); i++) {
                s.insert(Adj[temp][i].id);
            }
        }
        if (s.size() == m) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}