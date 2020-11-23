#include <cstdio>
#include <queue>
#include <stack>

using namespace std;

int main() {
    freopen("./sample_in/1051.txt", "r", stdin);
    int m, n, k;
    scanf("%d %d %d", &m, &n, &k);
    stack<int> s;
    while (k--) {
        queue<int> q;
        int temp;
        for (int i = 0; i < n; i++) {
            scanf("%d", &temp);
            q.push(temp);
        }
        int i;
        for (i = 1; i <= n; i++) {
            s.push(i);
            if (s.size() > m) {
                break;
            }
            while (!s.empty() && s.top() == q.front()) {
                s.pop();
                q.pop();
            }
        }
        if (q.empty() && i == n + 1) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
        while (!q.empty()) {
            q.pop();
        }
        while (!s.empty()) {
            s.pop();
        }
    }

    return 0;
}