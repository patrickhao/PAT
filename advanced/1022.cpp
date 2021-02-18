#include <bits/stdc++.h>
using namespace std;

unordered_map<string, vector<string>> mp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    string temp;
    getline(cin, temp);
    while (t--) {
        string id;
        vector<string> info(5);
        getline(cin, id);
        for (auto &v : info) getline(cin, v);
        mp[id] = info;
    }

    cin >> t;
    getline(cin, temp);
    while (t--) {
        getline(cin, temp);
        int ind = temp[0] - '1';
        string target = temp.substr(3, temp.length() - 3);

        set<string> st;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            if (ind == 2) {
                if (it->second[ind].find(target) != string::npos) st.insert(it->first);
            } else {
                if (it->second[ind] == target) st.insert(it->first);
            }
        }
        cout << temp << endl;
        if (st.size() == 0) cout << "Not Found" << endl;
        else for (auto it : st) cout << it << endl;
    }
    return 0;
}