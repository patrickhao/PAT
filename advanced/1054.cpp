#include <cstdio>
#include <map>

using namespace std;

int main() {
    freopen("./sample_in/1054.txt", "r", stdin);
    int m, n;
    map<long long, int> ans;
    scanf("%d %d", &m, &n);
    for (int i = 0; i < m * n; i++) {
        long long temp;
        scanf("%lld", &temp);
        if (ans.find(temp) != ans.end()) {
            ans[temp]++;
        } else {
            ans[temp] = 1;
        }
    }

    int MAX = -1;
    long long dc;
    for (auto it = ans.begin(); it != ans.end(); it++) {
        if (it->second > MAX) {
            MAX = it->second;
            dc = it->first;
        }
    }
    printf("%lld", dc);

    return 0;
}