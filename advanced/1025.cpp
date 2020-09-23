#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

typedef struct {
    char idNumber[15];
    int score;
    int location;
    int rankAll;
    int rankLocation;
} myScore;

bool cmp(myScore m1, myScore m2) {
    if(m1.score != m2.score) {
        return m1.score > m2.score;
    }
    else {
        return strcmp(m1.idNumber, m2.idNumber) < 0;
    }
}

int main() {
    freopen("./sample_in/1025.txt", "r", stdin);
    int N, K, allNums = 0;
    myScore score[101 * 301];
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &K);
        for(int j = 0; j < K; j++) {
            scanf("%s %d", &score[allNums].idNumber, &score[allNums].score);
            score[allNums].location = i + 1;
            allNums++;
        }
        sort(score + allNums - K, score + allNums, cmp);
        score[allNums - K].rankLocation = 1;
        for(int j = allNums - K + 1; j < allNums; j++) {
            if(score[j].score != score[j - 1].score) {
                score[j].rankLocation = j - (allNums - K) + 1;
            }
            else {
                score[j].rankLocation = score[j - 1].rankLocation;
            }
        }
    }
    sort(score, score + allNums, cmp);
    score[0].rankAll = 1;
    for(int i = 1; i < allNums; i++) {
        if(score[i].score != score[i - 1].score) {
            score[i].rankAll = i + 1;
        }
        else {
            score[i].rankAll = score[i - 1].rankAll;
        }
    }
    printf("%d\n", allNums);
    for(int i = 0; i < allNums; i ++) {
        printf("%s %d %d %d\n",score[i].idNumber, score[i].rankAll, score[i].location, score[i].rankLocation);
    }
    return 0;
}