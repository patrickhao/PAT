#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long LL;

LL convert(string s) {
    LL ans = 0;
    for (int i = 0; i < s.length(); i++)  {
        ans = ans * 10 + (s[i] - '0');
    }
    return ans;
}

int main() {
    freopen("./sample_in/1132.txt", "r", stdin);
    int n;
    cin >> n;
    while (n--) {
        string str;
        cin >> str;
        string s1 = str.substr(0, str.length() / 2);
        string s2 = str.substr(str.length() / 2, str.length() / 2);
        LL n = convert(str);
        LL n1 = convert(s1);
        LL n2 = convert(s2);
        if (n1 * n2 == 0) {
            cout << "No" << endl;
            continue;
        }
        if (n % (n1 * n2) == 0) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
        
    }

    return 0;
}