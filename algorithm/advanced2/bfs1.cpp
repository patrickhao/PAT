#include <cstdio>
#include <queue>

using namespace std;

const int maxn = 100;
struct node {
    int x, y;
} Node;

int m, n; // size: m * n
int matrix[maxn][maxn];
bool inq[maxn][maxn] = {false};
int X[4] = {0, 0, 1, -1}, Y[4] = {1, -1, 0, 0};

bool judge(int x, int y) {
    if(x >= n || x < 0 || y >= m || y < 0) {
        return false;
    }
    if(matrix[x][y] == 0 || inq[x][y]) {
        return false;
    }
    return true;
}

void bfs(int x, int y) {
    queue<node> q;
    Node.x = x, Node.y = y;
    q.push(Node);
    while(!q.empty()) {
        node top = q.front();
        q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = top.x + X[i];
            int ny = top.y + Y[i];
            if(judge(nx, ny)) {
                Node.x = nx, Node.y = ny;
                q.push(Node);
                inq[nx][ny] = true;
            }
        }
    }
}

int main() {
    freopen("data1.txt", "r", stdin);
    scanf("%d %d", &m, &n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(matrix[i][j] == 1 && !inq[i][j]) {
                ans++;
                bfs(i, j);
            }
        }
    }
    printf("%d", ans);

    return 0;
}