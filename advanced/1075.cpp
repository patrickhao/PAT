#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

struct elem{
    int user, score[5], sTag[5], sum, solvedNum, submit;

    elem() {
        user = sum = solvedNum = submit = 0;
        memset(score, 0, sizeof(score));
        memset(sTag, 0, sizeof(sTag));
    }
};

bool cmp(elem m, elem n) {
    if(m.sum != n.sum) {
        return m.sum > n.sum;
    }
    else if(m.solvedNum != n.solvedNum) {
        return m.solvedNum > n.solvedNum;
    }
    else {
        return m.user < n.user;
    }
}

const int maxn = 100000;

int main() {
    freopen("./sample_in/1075.txt", "r", stdin);
    int n, k, m, size = 0, fullScore[5] = {0};
    elem* data = (elem*)malloc(maxn * sizeof(elem));
    scanf("%d %d %d", &n, &k, &m);
    for(int i = 0; i < k; i++) {
        scanf("%d", fullScore + i);
    }
    int tuser, tprom, tscore;
    while(m--) {
        scanf("%d %d %d", &tuser, &tprom, &tscore);
        tprom--;
        data[tuser].user = tuser;
        data[tuser].sTag[tprom] = 1;
        if(tscore != -1) {
            data[tuser].submit = 1;
            if(tscore > data[tuser].score[tprom]) {
                data[tuser].sum += (tscore - data[tuser].score[tprom]);
                data[tuser].score[tprom] = tscore;
                if(tscore == fullScore[tprom]) {
                    data[tuser].solvedNum++;
                }
            }
        }
    }
    int index = 0;
    for(int i = 0; i < maxn; i++) {
        if(data[i].submit == 1) {
            size++;
        }
    }
    elem* rData = (elem*)malloc(size * sizeof(elem));
    for(int i = 0; i < maxn; i++) {
        if(data[i].submit == 1) {
            rData[index++] = data[i];
        }
    }
    sort(rData, rData + index, cmp);
    int rank = 1, cur = rData[0].sum;
    for(int i = 0; i < index; i++) {
        if(rData[i].sum != cur) {
            rank = i + 1;
            cur = rData[i].sum;
        }
        printf("%d %05d %d", rank, rData[i].user, rData[i].sum);
        for(int j = 0; j < k; j++) {
            if(rData[i].sTag[j] == 0) {
                printf(" -");
            } 
            else {
                printf(" %d", rData[i].score[j]);
            }
        }
        printf("\n");
    }
    return 0;
}