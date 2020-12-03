#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;
struct elem {
    string name;
    int gp, gm, gf, g;

    elem() {
        gp = gm = gf = g = -1;
    }
} D[100010];
int p, m, n, ind = 0, realNum = 0;
map<string, int> stringToInt;

bool cmp(elem e1, elem e2) {
    if (e1.g != e2.g) {
        return e1.g > e2.g;
    } else {
        return e1.name < e2.name;
    }
}

int getIndex(string s) {
    if (stringToInt.find(s) != stringToInt.end()) {
        return stringToInt[s];
    } else {
        stringToInt[s] = ind++;
        return stringToInt[s];
    }
}

int main() {
    freopen("./sample_in/1137.txt", "r", stdin);
    scanf("%d %d %d", &p, &m, &n);
    while (p--) {
        string temp;
        cin >> temp;
        int i = getIndex(temp);
        D[i].name = temp;
        scanf("%d", &D[i].gp);
    }
    while (m--) {
        string temp;
        cin >> temp;
        int i = getIndex(temp);
        D[i].name = temp;
        scanf("%d", &D[i].gm);
    }
    while (n--) {
        string temp;
        cin >> temp;
        int i = getIndex(temp);
        D[i].name = temp;
        scanf("%d", &D[i].gf);
    }
    for (int i = 0; i < ind; i++) {
        if (D[i].gp >= 200 && D[i].gf != -1) {
            realNum++;
            if (D[i].gm > D[i].gf) {
                D[i].g = round(D[i].gm * 0.4 + D[i].gf * 0.6);
            } else {
                D[i].g = D[i].gf;
            }
            if (D[i].g < 60) {
                realNum--;
            }
        }
    }
    sort(D, D + ind, cmp);
    for (int i = 0; i < realNum; i++) {
        cout << D[i].name;
        printf(" %d %d %d %d\n", D[i].gp, D[i].gm, D[i].gf, D[i].g);
    }

    return 0;
}