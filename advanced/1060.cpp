#include <iostream>
#include <string>

using namespace std;

int translate(string &s, int n) {
    while(s[0] == '0' && s.length() > 0) {
        s.erase(s.begin());
    }

    int size = 0;
    if(s[0] == '.') {
        s.erase(s.begin());
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '0') {
                if(i == s.length() - 1) {
                    size = 0;
                }
                else {
                    size--;
                }
            }
            else {
                break;
            }
        }
        while(s[0] == '0' && s.length() > 0) {
            s.erase(s.begin());
        }
    }
    else {
        if(s.find(".") != string::npos) {
            size = s.find(".");
            //s.replace(size, 1, "");
            s.erase(s.begin() + s.find("."));
        }
        else {
            size = s.length();
        }
    }

    if(s.length() <= n) {
        string temp = "";
        for(int i = 0; i < n - s.length(); i++) {
            temp += "0";
        }
        s = s + temp;
        s = "0." + s;
    }
    else {
        s = s.substr(0, n);
        s = "0." + s;
    }
    
    return size;
}

int main() {
    freopen("./sample_in/1060.txt", "r", stdin);
    int n, s1Len, s2Len;
    string s1, s2;
    cin >> n >> s1 >> s2;
    s1Len = translate(s1, n);
    s2Len = translate(s2, n);
    if(s1 == s2 && s1Len == s2Len) {
        cout << "YES "; 
    }
    else {
        cout << "NO ";
        cout << s1 + "*10^" << s1Len << " ";
    }
    cout << s2 + "*10^" << s2Len << endl;

    return 0;
}