#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    freopen("./sample_in/1067.txt", "r", stdin);
    int n, ans = 0;
    cin >> n;
    vector<int> d(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    if (d[0] == 0) {
        for (int i = 1; i < n; i++) {
            if (d[i] != i) {
                swap(d[i], d[0]);
                ans++;
                break;
            }
        }
    }
    int k = 1;
    while (true) {
        while (d[0] != 0) {
            swap(d[0], d[d[0]]);
            ans++;
        }
        bool flag = true;
        while(k < n) {
            if (d[k] != k) {
                flag = false;
                swap(d[k], d[0]);
                ans++;
                break;
            }
            k++;
        }
        if (flag) {
            break;
        }
    }
    cout << ans << endl;

    return 0;
}