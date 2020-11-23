#include <cctype>
#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

string s1[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string s2[13] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

int toInt(string s) {
    int ans = 0;
    for (int i = 0; i < s.length(); i++) {
        ans = ans * 10 + s[i] - '0';
    }
    return ans;
}


using namespace std;
int main() {
    freopen("./sample_in/1100.txt", "r", stdin);
    int n;
    map<string, int> dict1, dict2;
    map<int, string> cict1, cict2;
    for (int i = 0; i < 13; i++) {
        dict1[s1[i]] = i;
        cict1[i] = s1[i];
        dict2[s2[i]] = i;
        cict2[i] = s2[i];
    }

    cin >> n;
    getchar();
    while (n--) {
        string str;
        getline(cin, str);
        if (isdigit(str[0])) {
            vector<string> v;
            int num = toInt(str);
            bool flag = true;
            while (num) {
                int t = num % 13;
                if (flag) {
                    flag = false;
                    v.push_back(cict1[t]);
                } else {
                    v.push_back(cict2[t]);
                }
                num /= 13;
            }
            for (int i = v.size() - 1; i >= 0; i--) {
                cout << v[i];
                if (i != 0) {
                    cout << " ";
                } else {
                    cout << endl;
                }
            }
        } else {
            int i = 0, ans = 0, cn = 0, pn = 0;
            for (int i = 0; i < str.size(); i++) {
                if (str[i] == ' ') {
                    cn++;
                }
            }
            while (i < str.size()) {
                string word;
                while (isalpha(str[i])) {
                    word += str[i];
                    i++;
                }
                if (pn == cn) {
                    if (dict1[word] != 0) {
                        ans += dict1[word];
                    } else  {
                        ans += dict2[word] * 13;
                    }
                } else {
                    ans = 13 * (ans + dict2[word]);
                }
                pn++;
                if (!isalpha(str[i])) {
                    i++;
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}