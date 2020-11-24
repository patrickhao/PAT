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
    cin >> n;
    getchar();
    map<string, int> strToNum;
    map<int, string> numToStr;
    // 打表
    for (int i = 0; i < 13; i++) {
        strToNum[s1[i]] = i;
        strToNum[s2[i]] = 13 * i;
        numToStr[i] = s1[i];
        numToStr[13 * i] = s2[i];
    }
    for (int i = 1; i < 13; i++) {
        for (int j = 1; j < 13; j++) {
            string temp = numToStr[13 * i] + " " + numToStr[j];
            strToNum[temp] = 13 * i + j;
            numToStr[13 * i + j] = temp;
        }
    }
    string str;
    while (n--) {
        getline(cin, str);
        if (isdigit(str[0])) {
            int r = toInt(str);
            cout << numToStr[r] << endl;
        } else {
            cout << strToNum[str] << endl;
        }
    }
    return 0;
}