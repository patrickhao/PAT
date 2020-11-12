#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int maxn = 100;
struct node {
    int x, y;
    int step;
} S, T, Node;

int n, m;
char maze[maxn][maxn] = {0};
bool inq[maxn][maxn] = {false};
int X[4] = {0, 0, 1, -1}, Y[4] = {1, -1, 0, 0};

bool judge(int x, int y) {
    if(x >= n || x < 0 || y >= m || y < 0) {
        return false;
    }
    if(maze[x][y] == '*' || inq[x][y]) {
        return false;
    }
    return true;
}

int bfs() {
    queue<node> q;
    q.push(S);
    while(!q.empty()) {
        node top = q.front();
        q.pop();
        if(top.x == T.x && top.y == T.y) {
            return top.step;
        }
        for(int i = 0; i < 4; i++) {
            int nx = top.x + X[i];
            int ny = top.y + Y[i];
            if(judge(nx, ny)) {
                Node.x = nx;
                Node.y = ny;
                Node.step = top.step + 1;
                q.push(Node);
                inq[nx][ny] = true;
            }
        }
    }
    return -1;
}

int main() {
    freopen("data2.txt", "r", stdin);
    scanf("%d %d", &n, &m);
    getchar();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            maze[i][j] = getchar();
            getchar();
        }
    }
    scanf("%d %d %d %d", &S.x, &S.y, &T.x, &T.y);
    S.step = 0;
    printf("%d", bfs());

    return 0; 
}