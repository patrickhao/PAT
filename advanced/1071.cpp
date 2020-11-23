#include <cstdio>
#include <iostream>
#include <cctype>
#include <string>
#include <map>

using namespace std;

int main() {
    freopen("./sample_in/1071.txt", "r", stdin);
    string str;
    map<string, int> m;
    getline(cin, str);
    int i = 0;
    while (i < str.length()) {
        string word;
        while (isalnum(str[i])) {
            if (isalnum(str[i])) {
                word += tolower(str[i]);
            } else {
                word += str[i];
            }
            i++;
        }
        if (word != "") {
            if (m.find(word) != m.end()) {
                m[word]++;
            } else {
                m[word] = 1;
            }
        }
        while (!isalnum(str[i])) {
            i++;
        }
    }
    int MAX = -1;
    string out;
    for (auto it = m.begin(); it != m.end(); it++) {
        if (it->second > MAX) {
            MAX = it->second;
            out = it->first;
        }
    }
    cout << out << " " << MAX << endl;

    return 0;
}