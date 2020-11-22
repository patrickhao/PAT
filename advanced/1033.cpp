#include <cstdio>
#include <algorithm>

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
    bool finish = false, loopFlag = true;
    if (sta[0].dist != 0) {
        loopFlag = false;
    }
    while (loopFlag) {
        // find the next gas station
        int nextIndex = curIndex;
        for (int i = nextIndex + 1; i < n && sta[i].dist - sta[curIndex].dist <= dmax; i++) {
            if (sta[i].price < sta[curIndex].price) {
                nextIndex = i;
                break;
            }
        }
        if (nextIndex == curIndex) {
            double minPrice = 99999999.9;
            for (int i = nextIndex + 1; i < n && sta[i].dist - sta[curIndex].dist <= dmax; i++) {
                if (sta[i].price < minPrice) {
                    minPrice = sta[i].price;
                    nextIndex = i;
                }
            }
        }

        if (sta[nextIndex].price < sta[curIndex].price) {
            if (gasLeft * davg >= sta[nextIndex].dist - curDist) {
                gasLeft = gasLeft - (sta[nextIndex].dist - curDist) / davg;
            } else {
                cost = cost + ((sta[nextIndex].dist - curDist) / davg - gasLeft) * sta[curIndex].price;
                gasLeft = 0.0;
            }
            curDist = sta[nextIndex].dist;
            curIndex = nextIndex;
        } else {
            if (d - curDist <= dmax) {
                if (gasLeft * davg < d - curDist) {
                    cost = cost + ((d - curDist) / davg - gasLeft) * sta[curIndex].price;
                }
                finish = true;
                break;
            } else if (nextIndex == curIndex) {
                curDist += dmax;
                finish = false;
                break;
            } else {
                cost = cost + (cmax - gasLeft) * sta[curIndex].price;
                gasLeft = cmax - (sta[nextIndex].dist - curDist) / davg ;
                curDist = sta[nextIndex].dist;
                curIndex = nextIndex;
            }
        }
    }
    if (finish) {
        printf("%0.2f\n", cost);
    } else {
        printf("The maximum travel distance = %0.2f", curDist);
    }

    return 0;
}