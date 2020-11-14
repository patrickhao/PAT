#include <cctype>
#include <iostream>
#include <string>

using namespace std;

int main() {
    freopen("./sample_in/1042.txt", "r", stdin);
    string s;
    int hashTable[300] = {0};
    getline(cin, s);
    for(int i = 0; i < s.length(); i++) {
        if(isalpha(s[i])) {
            hashTable[tolower(s[i])]++;
        } else {
            hashTable[s[i]]++;
        }
    }

    char c;
    int maxSum = 0;
    for(int i = 'a'; i < 'z'; i++) {
        if(isalpha(i) && hashTable[i] > maxSum) {
            c = i;
            maxSum = hashTable[i];
        } 
    }
    printf("%c %d", c, maxSum);

    return 0;
}