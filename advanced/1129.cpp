#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int maxn = 50010;

struct elem {
    int id;
    int num;

    elem() {
        id = num = 0;
    }
} Data[maxn];

bool cmp(elem e1, elem e2) {
    if (e1.num != e2.num) {
        return e1.num > e2.num;
    } else {
        return e1.id < e2.id;
    }
}

int main() {
    freopen("./sample_in/1129.txt", "r", stdin);
    int n, k;
    vector<elem> D;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        int temp;
        bool changed = false;
        scanf("%d", &temp);
        if (i > 1) {
            printf("%d:", temp);
            for (elem e : D) {
                printf(" %d", e.id);
            }
            printf("\n");
        }
        if (Data[temp].id != 0) {
        } else {
            Data[temp].id = temp;
        }
        Data[temp].num++;
        elem e = Data[temp];
        if (D.empty()) {
            D.push_back(e);
            changed = true;
        } else if (D.size() < k) {
            bool sta = true;
            for (int i = 0; i < D.size(); i++) {
                if (D[i].id == e.id) {
                    D[i].num++;
                    sta = false;
                    changed = true;
                    break;
                }
            }
            if (sta) {
                D.push_back(e);
                changed = true;
            }
        } else if (D.size() == k) {
            bool sta = true;
            for (int i = 0; i < D.size(); i++) {
                if (D[i].id == e.id) {
                    D[i].num++;
                    sta = false;
                    changed = true;
                    break;
                }
            }
            if (sta) {
                if (D[D.size() - 1].num == e.num) {
                    if (D[D.size() - 1].id > e.id) {
                        D[D.size() - 1] = e;
                        changed = true;
                    }
                } else if (D[D.size() - 1].num < e.num) {
                    D[D.size() - 1] = e;
                    changed = true;
                }
            }
        }
        if (changed) {
            sort(D.begin(), D.end(), cmp);
        }
    }

    return 0;
}