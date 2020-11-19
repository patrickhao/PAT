#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct gs {
    double p, d;
};


bool cmp(gs g1, gs g2) {
    return g1.d < g2.d;
}

int main() {
    freopen("./sample_in/1033.txt", "r", stdin);
    vector<gs> gas;
    double cm, d, da, dm;
    int n;
    gs temp;
    scanf("%lf %lf %lf %d", &cm, &d, &da, &n);
    dm = cm * da;
    for(int i = 0; i < n; i++) {
        scanf("%lf %lf", &temp.p, &temp.d);
        gas.push_back(temp);
    }
    sort(gas.begin(), gas.end(), cmp);
    for(int i = 0; i < gas.size(); i++) {
        printf("%d: %.2f, %.2f\n", i, gas[i].d, gas[i].p);
    }

    int prePos = 0, pos = 0;
    double left = d, cost = 0.0;
    while(true) {
        double minPrice = 3000.0;
        for(int i = prePos + 1; i < gas.size(); i++) {
            if((gas[i].d - gas[prePos].d) > dm) {
                break;
            }
            if(gas[i].p < minPrice) {
                minPrice = gas[i].p;
                pos = i;
            }
        }
        if(prePos == pos || (gas[prePos].p <= gas[pos].p && left <= dm)) {
            if(left > dm) {
                left -= dm;
                cost = cost + dm / da * gas[prePos].p;
            } else {
                left = 0.0;
                cost = cost + left / da * gas[prePos].p;
            }
            break;
        } else {
            cost = cost + (gas[pos].d - gas[prePos].d) / da * gas[prePos].p;
            left = left - (gas[pos].d - gas[prePos].d);
            prePos = pos;
        }
    }

    if(left == 0.0) {
        printf("%.2f\n", cost);
    } else {
        printf("The maximum travel distance = %.2f\n", d - left);
    }

    return 0;
}