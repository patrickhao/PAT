#include <iostream>
#include <string>

using namespace std;

int main() {
    freopen("./sample_in/1029.txt", "r", stdin);
    string s1, s2;
    int hashTable[300] = {0};
    getline(cin, s1);
    getline(cin, s2);
    char c;
    for(int i = 0; i < s2.length(); i++) {
        c = toupper(s2[i]);
        hashTable[c] = 1;
    }
    for(int i = 0; i < s1.length(); i++) {
        c = toupper(s1[i]);
        if(!hashTable[c]) {
            hashTable[c]++;
            putchar(c);
        }
    }

    return 0;
}