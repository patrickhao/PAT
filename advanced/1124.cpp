#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
    freopen("./sample_in/1124.txt", "r", stdin);
    vector<string> wl;
    map<string, int> ma;
    int m, n, s;
    cin >> m >> n >> s;
    wl.push_back("");
    for (int i = 0; i < m; i++) {
        string str;
        cin >> str;
        wl.push_back(str);
    }
    if (s > m) {
        cout << "Keep going..." << endl;
    } else {
        int ss = s;
        for (int i = s; i < wl.size(); i++) {
            if ((i - ss) % n == 0) {
                if (ma.find(wl[i]) == ma.end()) {
                    ma[wl[i]] == 1;
                    cout << wl[i] << endl;
                } else {
                    for (; i < wl.size(); i++) {
                        if (ma.find(wl[i]) == ma.end()) {
                            ma[wl[i]] = true;
                            ss = i;
                            cout << wl[i] << endl;
                            break;
                        }
                    }
                }
            }
        }
    }

    return 0;
}