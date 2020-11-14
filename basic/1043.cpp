#include <iostream>
#include <string>

using namespace std;

int main() {
    freopen("./sample_in/1043.txt", "r", stdin);
    string s;
    int hashTable[300] = {0};
    getline(cin, s);
    for(int i = 0; i < s.length(); i++) {
        hashTable[s[i]]++;
    }
    while(hashTable['P'] > 0 || hashTable['A'] > 0 || hashTable['T'] > 0 || hashTable['e'] > 0 || hashTable['s'] > 0 || hashTable['t'] > 0) { 
        if(hashTable['P']-- > 0) {
            printf("P");
        }
        if(hashTable['A']-- > 0) {
            printf("A");
        }
        if(hashTable['T']-- > 0) {
            printf("T");
        }
        if(hashTable['e']-- > 0) {
            printf("e");
        }
        if(hashTable['s']-- > 0) {
            printf("s");
        }
        if(hashTable['t']-- > 0) {
            printf("t");
        }
    }

    return 0;
}