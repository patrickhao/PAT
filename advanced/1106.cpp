#include <cstdio>
#include <vector>
#include <queue>

using namespace std;
const int maxn = 100010;
int n;
double price, rate;

struct node {
    double p;
    vector<int> child;
} Tree[maxn];

int bfs(int root, double &pri) {
    queue<int> q;
    int ans = 0;
    q.push(root);
    Tree[root].p = price;
    while (!q.empty()) {
        int top = q.front();
        q.pop();
        if (Tree[top].child.size() != 0) {
            for (int i : Tree[top].child) {
                Tree[i].p = Tree[top].p * rate;
                q.push(i);
            }
        } else {
            if (Tree[top].p < pri) {
                pri = Tree[top].p;
                ans = 1;
            } else if (Tree[top].p == pri) {
                ans++;
            }
        }
    }
    return ans;
}

int main() {
    freopen("./sample_in/1106.txt", "r", stdin);
    scanf("%d %lf %lf", &n, &price, &rate);
    rate = 0.01 * rate + 1;
    for (int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        for (int j = 0; j < temp; j++) {
            int ttemp;
            scanf("%d", &ttemp);
            Tree[i].child.push_back(ttemp);
        }
    }
    double pri = 100000000;
    int num = bfs(0, pri);
    printf("%.4f %d", pri, num);

    return 0;
}