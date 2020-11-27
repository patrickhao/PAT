#include <cstdio>
#include <set>
#include <map>

using namespace std;
map<int, int> m;
set<int> ans;
bool arr[100000] = {false};

int main() {
    freopen("./sample_in/1121.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    while (n--) {
        int p1, p2;
        scanf("%d %d", &p1, &p2);
        m[p1] = p2;
        m[p2] = p1;
    }
    scanf("%d", &n);
    while (n--) {
        int temp;
        scanf("%d", &temp);
        arr[temp] = true;
    }
    for (int i = 0; i < 100000; i++) {
        if (arr[i] && !arr[m[i]]) {
            ans.insert(i);
        }
    }
    printf("%d\n", ans.size());
    int on = 0;
    for (auto it = ans.begin(); it != ans.end(); it++) {
        printf("%05d", *it);
        if (++on < ans.size()) {
            printf(" ");
        }
    }

    return 0;
}