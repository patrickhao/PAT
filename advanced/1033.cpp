#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 600;
struct station {
    double price, dist;
} sta[maxn];

bool cmp(station s1, station s2) {
    return s1.dist < s2.dist;
}
int main() {
    freopen("./sample_in/1033.txt", "r", stdin);
    double cmax, d, davg, dmax;
    int n;
    scanf("%lf %lf %lf %d", &cmax, &d, &davg, &n);
    dmax = cmax * davg;
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &sta[i].price, &sta[i].dist);
    }
    sort(sta, sta + n, cmp);

    double cost = 0.0, gasLeft = 0.0, curDist = 0.0;
    int curIndex = 0;
    bool finish = false;
    while (true) {
        if (curIndex == n - 1) {
            if (d - curDist <= dmax) {
                if (gasLeft * davg < d - curDist) {
                    cost = cost + ((d - curDist) / davg - gasLeft) * sta[curIndex].price;
                }
                finish = true;
                break;
            } else {
                finish = false;
                break;
            }
        } else {
            int i = curIndex + 1, minIndex = 0;
            double cDist = -1.0, minPrice = 99999999.9;
            while (i < n && sta[i].dist - sta[curIndex].dist <= dmax) {
                if (sta[i].price < minPrice) {
                    minPrice = sta[i].price;
                    cDist = sta[i].dist - sta[curIndex].dist;
                    minIndex = i;
                }
                i++;
            }
            if (cDist == -1.0) {
                finish = false;
                curDist = sta[curIndex].dist + dmax;
                cost = cost + (cmax - gasLeft) * sta[curIndex].price;
                break;
            } else if (minPrice < sta[curIndex].price) {
                if (gasLeft * davg >= cDist) {
                    gasLeft = gasLeft - cDist / davg;
                } else {
                    gasLeft = 0;
                    cost = cost + (cDist / davg - gasLeft) * sta[curIndex].price;
                }
                curDist = sta[minIndex].dist;
                curIndex = minIndex;
            } else {
                if (d - curDist <= dmax) {
                    if (gasLeft * davg >= (d - curDist)) {
                        gasLeft = gasLeft - (d - curDist) / davg;
                    } else {
                        gasLeft = 0;
                        cost = cost + ((d - curDist) / davg - gasLeft) * sta[curIndex].price;
                    }
                    finish = true;
                    break;
                } else {
                    gasLeft = cmax - cDist / davg;
                    cost = cost + (cmax - gasLeft) * sta[curIndex].price;
                    curDist = sta[minIndex].dist;
                    curIndex = minIndex;
                }
            }
        }
    }
    printf("%f", cost);
    
    return 0;
}