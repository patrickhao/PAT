#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

void cal(int &m, int &n, int N) {
    m = n = (int)sqrt(N);
    for (int i = m; i <= N; i++) {
        for (int j = n; j >= 1; j--) {
            if (i * j == N) {
                m = i;
                n = j;
                return;
            }
        }
    }
}

int main() {
    freopen("./sample_in/1105.txt", "r", stdin);
    int N, m, n;
    cin >> N;
    cal(m, n, N);
    vector<int> arr(N);
    vector<vector<int>> ans(m, vector<int>(n));
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end(), cmp);
    int index = 0, w = 0;
    while (index < N) {
        for (int i = w; i < n - w && index < N; i++) {
            ans[w][i] = arr[index++];
        }
        for (int i = w + 1; i < m - w && index < N; i++) {
            ans[i][n - w - 1] = arr[index++]; 
        }
        for (int i = n - w - 2; i >= 0 && index < N; i--) {
            ans[m - w - 1][i] = arr[index++];
        }
        for (int i = m - w - 2; i > w && index < N; i--) {
            ans[i][w] = arr[index++];
        }
        w++;
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j];
            if (j < n - 1) {
                cout << " ";
            } else {
                cout << endl;
            }
        }
    }

    return 0;
}