#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    freopen("./sample_in/1033.txt", "r", stdin);
    string s1, s2;
    int hashTable[300] = {0};
    getline(cin, s1);
    getline(cin, s2);

    for(int i = 0; i < s1.length(); i++) {
        char c = s1[i];
        if(c == '+') {
            for(int i = 'A'; i < 'Z'; i++) {
                hashTable[i] = 1;
            }
        } else if(isalpha(c)) {
            hashTable[c] = 1;
            hashTable[c + 'a' - 'A'] = 1;
        } else {
            hashTable[c] = 1;
        }
    }
    for(int i = 0; i < s2.length(); i++) {
        char c = s2[i];
        if(!hashTable[c]) {
            putchar(c);
        }
    }
    putchar('\n');


    return 0;
}