#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int n, amount, MIN = 1000000000;
int c[100010];
map<int, int> ans1, ans2;

int arrSum(int left, int right) {
    if (left == 0) {
        return c[right];
    } else {
        return c[right] - c[left - 1];
    }
}

int binarySearch(int left, int right) {
    int mid, ol = left;
    while (left < right) {
        mid = (left + right) / 2;
        int as = arrSum(ol, mid);
        if (as >= amount) {
            right = mid; 
        } else {
            left = mid + 1;
        }
    }
    return left;
}


int main() {
    freopen("./sample_in/1044.txt", "r", stdin);
    scanf("%d %d", &n, &amount);
    for (int i = 0; i < n; i++) {
        scanf("%d", c + i);
        if (i != 0) {
            c[i] += c[i - 1];
        }
    }

    for (int i = 0; i < n; i++) {
        int r = binarySearch(i, n - 1);
        if (arrSum(i, r) == amount) {
            ans1[i + 1] = r + 1;
        } else {
            if (arrSum(i, r) < MIN && arrSum(i, r) > amount) {
                MIN = arrSum(i, r);
                ans2.clear();
                ans2[i + 1] = r + 1;
            } else if (arrSum(i, r) == MIN) {
                ans2[i + 1] = r + 1;
            }
        }
    }
    if (ans1.size() != 0) {
        for (auto it = ans1.begin(); it != ans1.end(); it++) {
            cout << it->first << "-" << it->second << endl;
        }
    } else {
        for (auto it = ans2.begin(); it != ans2.end(); it++) {
            cout << it->first << "-" << it->second << endl;
        }
    }
    return 0;
}