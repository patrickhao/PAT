#include <cstdio>
#include <queue>

using namespace std;

int m, n, l, t;
int D[1290][130][61];
bool inq[1290][130][61] = {false};
int X[6] = {1, -1, 0, 0, 0, 0};
int Y[6] = {0, 0, 1, -1, 0, 0};
int Z[6] = {0, 0, 0, 0, 1, -1};

struct elem {
    int x, y, z;
};

bool judge(int x, int y, int z) {
    if (inq[x][y][z] || D[x][y][z] == 0) {
        return false;
    }
    if (x < 0 || y < 0 || z < 0 || x >= m || y >= n || z >= l) {
        return false;
    }
    return true;
}

elem e;
int bfs(int x, int y, int z) {
    int a = 0;
    queue<elem> q;
    e.x = x;
    e.y = y;
    e.z = z;
    q.push(e);
    inq[x][y][z] = true;
    while (!q.empty()) {
        elem top = q.front();
        q.pop();
        a++;
        for (int i = 0; i < 6; i++) {
            int nx = top.x + X[i];
            int ny = top.y + Y[i];
            int nz = top.z + Z[i];
            if (judge(nx, ny, nz)) {
                e.x = nx;
                e.z = ny;
                e.z = nz;
                q.push(e);
                inq[nx][ny][nz] = true;
            }
        }
    }
    return a >= t ? a : 0;
}

int main() {
    freopen("./sample_in/1091.txt", "r", stdin);
    int ans = 0;
    scanf("%d %d %d %d", &m, &n, &l, &t);
    for (int k = 0; k < l; k++) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &D[i][j][k]);
            }
        }
    }
    for (int k = 0; k < l; k++) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (inq[i][j][k] == false && D[i][j][k] == 1) { 
                    ans += bfs(i, j, k);
                }
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}