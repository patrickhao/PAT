#include <cmath>
#include <iostream>
#include <set>

using namespace std;
const int maxn = 1010;
int arr[maxn];

int main() {
    freopen("./sample_in/1128.txt", "r", stdin);
    int k;
    cin >> k;
    while (k--) {
        int n;
        set<int> s;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            s.insert(arr[i]);
        }
        if (s.size() != n) {
            cout << "NO" << endl;
            continue;
        }
        int flag = true;
        for (int i = 0; i < n; i++) {
            if (flag) {
                for (int j = i + 1; j < n; j++) {
                    if (abs(i - j) == abs(arr[i] - arr[j])) {
                        flag = false;
                        break;
                    }
                }
            }
        }
        if (flag) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}