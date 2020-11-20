#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

struct ts {
    int h, m, s;
};
struct elem {
    ts it, st;
    int sta, delTag;

    elem() {
        delTag = 0;
    }
} d[10010];

int cIndex = 0;
map<string, int> cid;
map<int, string> cname;

bool cmp1(elem e1, elem e2) {
    if(e1.delTag != e2.delTag) {
        return e1.delTag < e2.delTag;
    }
}

int stringToInt(string str) {
    if(cid.find(str) != cid.end()) {
        return cid[str];
    } else {
        cid[str] = cIndex;
        cname[cIndex++] = str;
        return cid[str];
    }
}

int main() {
    freopen("./sample_in/1095.txt", "r", stdin);
    int n, k;
    cin >> n >> k;
    int carNum = 0;
    for(int i = 0; i < n; i++) {
        string str, sta;
        int h, m, s;
        ts ttemp;
        cin >> str;
        scanf("%d:%d:%d", &ttemp.h, &ttemp.m, &ttemp.s);
        cin >> sta;
        int ind = stringToInt(str);
        if(sta[0] == 'i') {
            if(d[ind].sta != 0) {
                d[ind].delTag = 1;
            } else {
                d[ind].sta = 1;
                d[ind].it = ttemp;
            }
        } else {
            if(d[ind].sta == 1 && d[ind].delTag == 0) {
                d[ind].sta = 2;
                ts st;
                if(d[ind].it.s <= ttemp.s) {
                    st.s = ttemp.s - d[ind].it.s;
                } else {
                    st.s = ttemp.s + 60 - d[ind].it.s;
                    ttemp.m--;
                }
                if(d[ind].it.m <= ttemp.m) {
                    st.m = ttemp.m - d[ind].it.m;
                } else {
                    st.m = ttemp.m + 60 - d[ind].it.m;
                    ttemp.h--;
                }
                st.h = ttemp.h - d[ind].it.h;
                d[ind].st = st;
                carNum++;
            } else {
                d[ind].delTag = 1;
            }
        }
    }
    cout << carNum << endl;
    cout << cid.size() << endl;
    return 0;
}