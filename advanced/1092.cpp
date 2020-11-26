#include <cctype>
#include <iostream>
#include <string>

using namespace std;

int convert(char c) {
    if (isdigit(c)) {
        return c - '0';
    } else if (isupper(c)) {
        return c - 'A' + 10;
    } else if (islower(c)) {
        return c - 'a' + 36;
    }
    return -1;
}

int main() {
    freopen("./sample_in/1092.txt", "r", stdin);
    string s1, s2;
    int hashTable[100] = {0};
    cin >> s1 >> s2;
    for (int i = 0; i < s1.length(); i++) {
        hashTable[convert(s1[i])]++;
    }
    for (int i = 0; i < s2.length(); i++) {
        hashTable[convert(s2[i])]--;
    }
    int n1 = 0, n2 = 0;
    for (int i = 0; i < 100; i++) {
        if (hashTable[i] > 0) {
            n1 += hashTable[i];
        } else {
            n2 -= hashTable[i];
        }
    }
    if (n2 > 0) {
        printf("No %d\n", n2);
    } else {
        printf("Yes %d\n", n1);
    }

    return 0;
}