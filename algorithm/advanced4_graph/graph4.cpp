#include <iostream>
#include <algorithm>

using namespace std;

const int MAXV = 200;
const int INF = 1000000000;
int n, m;
int dis[MAXV][MAXV];

void floyd() {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dis[i][k] != INF && dis[k][j] != INF && dis[i][k] + dis[k][j] < dis[i][j]) {
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }
}

int main() {
    fill(dis[0], dis[0] + MAXV * MAXV, INF);
    for (int i = 0; i < n; i++) {
        dis[i][i] = 0;
    }
    return 0;
}