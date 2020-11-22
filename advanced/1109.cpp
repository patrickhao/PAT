#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

struct elem {
    string name;
    int height;
} d[10010];

bool cmp(elem e1, elem e2) {
    if (e1.height != e2.height) {
        return e1.height > e2.height;
    } else {
        return e1.name < e2.name;
    }
}

int main() {
    freopen("./sample_in/1109.txt", "r", stdin);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        elem temp;
        cin >> temp.name >> temp.height;
        d[i] = temp;
    }
    sort(d, d + n, cmp);
    
    int left = 0, right = n - (n / k) * (k - 1) - 1;
    for (int i = 0; i < k; i++) {
        if (i > 0) {
            left = right + 1;
            right = right + n / k;
        }
        int index = left, mi, li, ri;
        mi = (right - left + 1) / 2;
        li = mi - 1;
        ri = mi + 1;
        vector<string> ans(2 * (n / k));
        ans[mi] = d[index].name;
        //left
        for (int j = index + 1; j <= right; j += 2) {
            ans[li--] = d[j].name;
        }
        //right
        for (int j = index + 2; j <= right; j += 2) {
            ans[ri++] = d[j].name;
        }
        for (int j = 0; j < ri; j++) {
            cout << ans[j];
            if (j != ri - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}