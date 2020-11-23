#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>

using namespace std;

vector<set<int>> ans(180000);

int translate(string name) {
    int ans = 0;
    for (int i = 0; i < name.size() - 1; i++) {
        ans = ans * 26 + name[i] - 'A';
    }
    ans = ans * 10 + name[name.size() - 1] - '0';
    return ans;
}

int main() {
    freopen("./sample_in/1039.txt", "r", stdin);
    int n, k;
    cin >> n >> k;
    while (k--) {
        int id, ni;
        cin >> id >> ni;
        while (ni--) {
            string temp;
            cin >> temp;
            ans[translate(temp)].insert(id);
        }
    }
    while (n--) {
        string temp;
        cin >> temp;
        cout << temp;
        cout << " " << ans[translate(temp)].size();
        for (auto it = ans[translate(temp)].begin(); it != ans[translate(temp)].end(); it++) {
            cout << " " << *it;
        }
        cout << endl;
    }

    return 0;
}