#include <iostream>
#include <string>

using namespace std;

int main() {
    freopen("./sample_in/1039.txt", "r", stdin);
    string s1, s2;
    int hashTable[300] = {0};
    getline(cin, s1);
    getline(cin, s2);
    for(int i = 0; i < s1.length(); i++) {
        hashTable[s1[i]]++;
    }
    
    int numAll = s2.length();
    for(int i = 0; i < s2.length(); i++) {
        if(hashTable[s2[i]] > 0) {
            hashTable[s2[i]]--;
            numAll--;
        }
    }
    if(numAll == 0) {
        printf("Yes %d", s1.length() - s2.length());
    } else {
        printf("No %d", numAll);
    }

    return 0;
}