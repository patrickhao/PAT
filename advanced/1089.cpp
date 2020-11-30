#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    freopen("./sample_in/1089.txt", "r", stdin);
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> brr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> brr[i];
    }

    return 0;
}