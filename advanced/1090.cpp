#include <cstdio>
#include <vector>
#include <queue>

using namespace std;
const int maxn = 100010;
int n, root;
double price, rate;

struct node {
    double p;
    vector<int> child;
} Tree[maxn];

int bfs(int root, double &maxPri) {
    int ans = 0;
    queue<int> q;
    q.push(root);
    Tree[root].p = price;
    while (!q.empty()) {
        int top = q.front();
        q.pop();
        if (Tree[top].child.size() != 0) {
            for (int i = 0; i < Tree[top].child.size(); i++) {
                int c = Tree[top].child[i];
                Tree[c].p = Tree[top].p * rate;
                q.push(c);
            }
        } else {
            if (Tree[top].p > maxPri) {
                maxPri = Tree[top].p;
                ans = 1;
            } else if (Tree[top].p == maxPri) {
                ans++;
            }
        }
    }
    return ans;
}

int main() {
    freopen("./sample_in/1090.txt", "r", stdin);
    scanf("%d %lf %lf", &n, &price, &rate);
    rate = 0.01 * rate + 1;
    for (int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        if (temp != -1) {
            Tree[temp].child.push_back(i);
        } else {
            root = i;
        }
    }
    double mp = 0.0;
    int num = bfs(root, mp);
    printf("%.2f %d\n", mp, num);

    return 0;
}