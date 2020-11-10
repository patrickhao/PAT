#include <iostream>
#include <cctype>

using namespace std;

int main() {
    //cctype好用的功能
    //isalpha、islower、isupper、isalnum、isblank、isspace
    char c = 'a';
    //cin >> c;
    if(isalpha(c)) {
        cout << c << " is a alpha" << endl;
    }

    c = toupper(c);
    cout << c << endl;

    return 0;
}