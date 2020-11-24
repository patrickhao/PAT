#include <cstdio>
#include <vector>
#include <queue>

using namespace std;
const int maxn = 100010;
int n;
double price, rate;

struct node {
    int s;
    double p;
    vector<int> child;
} Tree[maxn];

double bfs(int root) {
    double ans = 0.0;
    queue<int> q;
    q.push(root);
    Tree[root].p = price;
    while(!q.empty()) {
        int top = q.front();
        q.pop();
        if (Tree[top].child.size() != 0) {
            for (int i = 0; i < Tree[top].child.size(); i++) {
                int c = Tree[top].child[i];
                Tree[c].p = Tree[top].p * rate;
                q.push(c);
            }
        } else {
            ans = ans + Tree[top].p * Tree[top].s;
        }
    }
    return ans;
}

int main() {
    freopen("./sample_in/1079.txt", "r", stdin);
    scanf("%d %lf %lf", &n, &price, &rate);
    rate = 0.01 * rate + 1;
    for (int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        if (temp == 0) {
            scanf("%d", &temp);
            Tree[i].s = temp;
        } else {
            while (temp--) {
                int ttemp;
                scanf("%d", &ttemp);
                Tree[i].child.push_back(ttemp);
                Tree[i].s = 0;
            }
        }
    }
    printf("%.1f\n", bfs(0));

    return 0;
}