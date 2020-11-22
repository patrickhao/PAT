#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n, p, i;
vector<int> arr(n);

void binarySearch(int left, int right) {
    int mid;
    while (left <= right) {
        if (arr[mid] <= arr[i] * p) {
            
        }
    }
}

int main() {
    freopen("./sample_in/1085.txt", "r", stdin);
    cin >> n >> p;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    return 0;
}