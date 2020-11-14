#include <cstdio>
#include <algorithm>

using namespace std;

struct elem {
    int w;
    int p;
} w[1010], wt[1010];
int ans[1010] = {0};

elem whowin(int left, int right, int rank) {
    elem max;
    max.w = -1;
    for(int i = left; i < right; i++) {
        if(w[i].w > max.w) {
            max = w[i];
        }
    }
    for(int i = left; i < right; i++) {
        if(w[i].w != max.w) {
            ans[w[i].p] = rank;
        }
    }
    return max;
}


int main() {
    freopen("./sample_in/1056.txt", "r", stdin);
    int np, ng;
    scanf("%d %d", &np, &ng);
    for(int i = 0; i < np; i++) {
        scanf("%d", &wt[i].w);
        wt[i].p = i;
    }
    for(int i = 0; i < np; i++) {
        int temp;
        scanf("%d", &temp);
        w[i] = wt[temp];
    } 

    int numleft = np, rankNow = 1;
    for(int i = 0; numleft > 1; i++) {
        int index = 0;
        int times = numleft % ng == 0 ? numleft / ng : numleft / ng + 1;
        for(int j = 0; j < times; j++) {
            int left = ng * j, right = ng * (j + 1) > numleft ? numleft : ng * (j + 1);
            w[index++] = whowin(left, right, rankNow); 
        }
        rankNow++;
        numleft = index;
    }
    ans[w[0].p] = rankNow;

    int rankBase = 1, rankTemp = 1, top = rankNow, out[1010] = {0};
    for(int i = 0; i < rankNow; i++) {
        for(int j = 0; j < np; j++) {
            if(ans[j] == top) {
                out[j] = rankBase;
                rankTemp++;
            }
        }
        top--;
        rankBase = rankTemp;
    }
    for(int i = 0; i < np - 1; i++) {
        printf("%d ", out[i]);
    }
    printf("%d", out[np - 1]);

    return 0;
}