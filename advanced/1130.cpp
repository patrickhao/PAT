#include <iostream>
#include <string>

using namespace std;
const int maxn = 30;
struct node {
    string data;
    int lchild, rchild;
} T[maxn];
bool isRoot[maxn] = {false};

string dfs(int r) {
    if (T[r].lchild == -1 && T[r].rchild == -1) {
        return T[r].data;
    } else if (T[r].lchild == -1 && T[r].rchild != -1) {
        return "(" + T[r].data + dfs(T[r].rchild) + ")";
    } else if (T[r].lchild != -1 && T[r].rchild != -1) {
        return "(" + dfs(T[r].lchild) + T[r].data + dfs(T[r].rchild) + ")";
    }
    return "";
}

int main() {
    freopen("./sample_in/1130.txt", "r", stdin);
    int n, root = 1;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int l, r;
        cin >> T[i].data >> T[i].lchild >> T[i].rchild;
        isRoot[T[i].lchild] = isRoot[T[i].rchild] = true;
    }
    while (isRoot[root]) {
        root++;
    }
    string ans = dfs(root);
    if (ans[0] == '(') {
        ans = ans.substr(1, ans.length() - 2);
    }
    cout << ans << endl;
    return 0;
}