#include <cctype>
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;
int k;
vector<char> ans;
string str;

int main() {
    freopen("./sample_in/1112.txt", "r", stdin);
    scanf("%d ", &k);
    getline(cin, str);
    int cur = 0;
    while (cur < str.length()) {
        if (isalnum(str[cur]) || str[cur] == '_') {
            int num = 1;
            while (cur < str.length() && str[cur + 1] == str[cur]) {
                num++;
                cur++;
            }
            int index = -1;
            for (int i = 0; i < ans.size(); i++) {
                if (ans[i] == str[cur]) {
                    index = i;
                    break;
                }
            }
            if (index == -1 && num % k == 0) {
                ans.push_back(str[cur]);
            } else if (index != -1 && num % k != 0) {
                ans[index] = -1;
            }
            cur++;
        }
    }
    map<char, int> m;
    for (int i = 0; i < ans.size(); i++) {
        if (ans[i] != -1) {
            cout << ans[i];
            m[ans[i]] = 1;
        }
    }
    cout << endl;
    for (int i = 0; i < str.size(); i++) {
        cout << str[i];
        if (m[str[i]] == 1) {
            i = i + k - 1;
        }
    }


    return 0;
}