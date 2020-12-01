#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std; 
const int maxn = 100010;
   
struct ti {
    int h, m, s;
};

struct node {
    ti t;
    string cid;
    bool flag;
} rec[maxn];

bool cmp(node n1, node n2) {
    if (n1.t.h != n2.t.h) {
        return n1.t.h < n2.t.h;
    } else if (n1.t.m != n2.t.m) {
        return n1.t.m < n2.t.m;
    } else if (n1.t.s < n2.t.s) {
        return n1.t.s < n2.t.s;
    } else {
        return n1.cid < n2.cid;
    }
}

int main() {
    freopen("./sample_in/1095.txt", "r", stdin);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> rec[i].cid;
        scanf("%d:%d:%d", &rec[i].t.h, &rec[i].t.m, &rec[i].t.s);
        string temp;
        cin >> temp;
        if (temp == "in") {
            rec[i].flag = true;
        } else {
            rec[i].flag = false;
        }
    }
    sort(rec, rec + n, cmp);
    for (int i = 0; i < n; i++) {
        cout << rec[i].cid;
        printf(" %02d:%02d:%02d\n", rec[i].t.h, rec[i].t.m, rec[i].t.s);
    }
    int rn = 0;
    map<string, int> mmap;
    for (int i = 0; i < n; i++) {
        if ()
    }

    return 0;
}