#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int INF = 1000000000;
int d[100010];
int dmax[100010], dmin[100010];

int main() {
    freopen("./sample_in/1101.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", d + i);
    }
    dmax[0] = -INF;
    dmin[n - 1] = INF;
    for (int i = 1; i < n; i++) {
        dmax[i] = max(d[i - 1], dmax[i - 1]);
    }
    for (int i = n - 2; i >= 0; i--) {
        dmin[i] = min(dmin[i + 1], d[i + 1]);
    }

    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (dmax[i] < d[i] && dmin[i] > d[i]) {
            ans.push_back(d[i]);
        }
    } 
    
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
        if (i != ans.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}