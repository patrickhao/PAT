#include <iostream>
#include <string>

using namespace std;

int main() {
    freopen("./sample_in/1050.txt", "r", stdin);
    string s1, s2;
    int hashTable[300] = {0};
    getline(cin ,s1);
    getline(cin, s2);
    for(int i = 0; i < s2.length(); i++) {
        hashTable[s2[i]]++;
    }
    for(int i = 0; i < s1.length(); i++) {
        if(hashTable[s1[i]] == 0) {
            putchar(s1[i]);
        }
    }
    return 0;
}