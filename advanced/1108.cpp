#include <cctype>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

double convert(string str) {
    double ans = 0.0, t = 0.1;
    int tag = 1, index = 0;
    bool p = true;
    if (str[0] == '-') {
        tag = -1;
        index++;
    }
    while (index < str.length()) {
        if (p) {
            if (str[index] == '.') {
                p = false;
                index++;
                continue;
            }
            ans = ans * 10 + str[index++] - '0';
        } else {
            ans = ans + (str[index++] - '0') * t;
            t *= 0.1;
        }
    }
    return ans * tag;
}

bool judge(string str) {
    int i = 0;
    int pn = 0;
    if (str[0] == '-') {
        i++;
    }
    for (; i < str.length(); i++) {
        if (isalpha(str[i]) || str[i] == '-') {
            return false;
        } else if (str[i] == '.') {
            if (str.length() - 1 > i + 2) {
                return false;
            }
            pn++;
            if (pn > 1) {
                return false;
            }
        }
    }
    double temp = convert(str);
    if (temp < -1000 || temp > 1000) {
        return false;
    }
    return true;
}

int main() {
    freopen("./sample_in/1108.txt", "r", stdin);
    int n, rn = 0;
    double s = 0.0;
    scanf("%d", &n);
    while (n--) {
        string str;
        cin >> str;
        if (judge(str)) {
            rn++;
            s += convert(str);
        } else {
            cout << "ERROR: " + str + " is not a legal number" << endl;
        }
    }
    if (rn == 0) {
        printf("The average of 0 numbers is Undefined\n");
    } else if (rn == 1) {
        printf("The average of %d number is %.2f\n", rn, s / rn);
    } else {
        printf("The average of %d numbers is %.2f\n", rn, s / rn);
    }

    return 0;
}