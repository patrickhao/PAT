#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
const int MAXN = 1010;
struct Node {
    int val;
    int layer;
};

int n, l;
vector<Node> Adj[MAXN];
bool inq[MAXN] = {false};

int bfs(int target) {
    int ans = 0;
    queue<Node> q;
    Node start;
    start.val = target;
    start.layer = 0;
    q.push(start);
    inq[start.val] = true;
    while (!q.empty()) {
        Node topNode = q.front();
        q.pop();
        int u = topNode.val;
        if (topNode.layer <= l && topNode.val != target) {
            ans++;
        } 
        for (int i = 0; i < Adj[u].size(); i++) {
            Node next = Adj[u][i];
            next.layer = topNode.layer + 1;
            if (!inq[next.val]) {
                q.push(next);
                inq[next.val] = true;
            }
        }
    }
    return ans;
}

int main() {
    freopen("./sample_in/1076.txt", "r", stdin);
    scanf("%d %d", &n, &l);
    for (int i = 1; i <= n; i++) {
        Node curNode;
        curNode.val = i;
        int fn;
        scanf("%d", &fn);
        while (fn--) {
            int temp;
            scanf("%d", &temp);
            Adj[temp].push_back(curNode); 
        }
    }

    int k;
    scanf("%d", &k);
    while (k--) {
        int userid;
        scanf("%d", &userid);
        fill(inq, inq + MAXN, false);
        printf("%d\n", bfs(userid));
    }

    return 0;
}