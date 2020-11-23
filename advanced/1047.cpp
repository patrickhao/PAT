#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;
    
vector<set<string>> ans(2510);

int main() {
    freopen("./sample_in/1047.txt", "r", stdin);
    int n, k;
    scanf("%d %d", &n, &k);
    while (n--) {
        string name;
        cin >> name;
        int num;
        scanf("%d", &num);
        while (num--) {
            int index;
            cin >> index;
            ans[index].insert(name);
        }
    }
    int outNum = 0;
    for (int i = 0; i < 2510; i++) {
        if (ans[i].size() != 0) {
            cout << i << " " << ans[i].size() << endl;
            for (auto it = ans[i].begin(); it != ans[i].end(); it++) {
                cout << *it << endl;
            }
            outNum++;
            if (outNum == k) {
                break;
            }
        }
    }

    return 0;
}