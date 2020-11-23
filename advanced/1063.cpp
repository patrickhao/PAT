#include <iostream>
#include <set>
#include <map>
#include <vector>

using namespace std;

vector<set<int>> d(60);

int main() {
    freopen("./sample_in/1063.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int m;
        scanf("%d", &m);
        while (m--) {
            int temp;
            scanf("%d", &temp);
            d[i].insert(temp);
        }
    }
    
    int k;
    scanf("%d", &k);
    while (k--) {
        int n1, n2;
        scanf("%d %d", &n1, &n2);
        set<int> s1 = d[n1];
        set<int> s2 = d[n2];
        int nc = 0, nt = s1.size() + s2.size();
        double rate;
        for (auto it = s1.begin(); it != s1.end(); it++) {
            if (s2.find(*it) != s2.end()) {
                nc++;
                nt--;
            }
        }
        rate = (double)nc / nt;
        printf("%0.1f%%\n", rate * 100);
    }

    return 0;
}