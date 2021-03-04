#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n; scanf("%d %d", &m, &n);
    vector<int> arr(n);
    set<int> st;
    for (int &v : arr) {
        scanf("%d", &v);
        st.insert(v);
    }
    while (m--) {
        int a, b; scanf("%d %d", &a, &b);
        int lca = 0;
        for (auto v : arr) {
            if ((v > a && v < b) || (v > b && v < a) || (v == a) || (v == b)) {
                lca = v;
                break;
            }
        }
        if (st.count(a) == 0 && st.count(b) == 0) printf("ERROR: %d and %d are not found.\n", a, b);
        else if (st.count(a) == 0 || st.count(b) == 0) printf("ERROR: %d is not found.\n", st.count(a) == 0 ? a : b);
        else if (lca == a || lca == b) printf("%d is an ancestor of %d.\n", lca, lca == a ? b : a);
        else printf("LCA of %d and %d is %d.\n", a, b, lca);
    }
    return 0;
}