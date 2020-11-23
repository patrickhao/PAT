#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;
int d[100010];
int dmax[100010], dmin[100010];

int main() {
    freopen("./sample_in/1101.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    scanf("%d", &d[0]);
    dmax[0] = d[0];
    for (int i = 1; i < n; i++) {
        scanf("%d", d + i);
        dmax[i] = max(dmax[i - 1], d[i]);
    }
    dmin[n - 1] = d[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        dmin[i] = min(dmin[i + 1], d[i]);
    }

    set<int> ans;
    for (int i = 0; i < n; i++) {
        if (dmax[i] <= d[i] && dmin[i] >= d[i]) {
            ans.insert(i + 1);
        }
    } 
    
    int num = 0;
    cout << ans.size() << endl;
    for (auto it = ans.begin(); it != ans.end(); it++) {
        cout << *it;
        if (num++ != ans.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}