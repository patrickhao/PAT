#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct elem {
    string s;
    int val;
} d[10010];

int main() {
    freopen("./sample_in/1038.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> d[i].s;
        d[i].val = stoi(d[i].s);
    }


    return 0;
}