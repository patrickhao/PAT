/*
1、使用多余的变量和数组，没有观察到preNums = allNums - K
2、一个循环能完成的任务拆到两个循环，产生大量多余变量传递两个循环之间的参数
3、变量名取得太长
*/
#include <cstdio>
#include <algorithm>
#include <cstdlib>
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
    int N, K, allNums = 0, preNums = 0, locationScoreIndex = 0, preLocationScoreIndex = 0;
    myScore score[101 * 301];
    scanf("%d", &N);
    int* krray = (int*)malloc(sizeof(int) * N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &K);
        krray[i] = K;
        for(int j = 0; j < K; j++) {
            scanf("%s %d", &score[preNums + j].idNumber, &score[preNums + j].score);
            score[preNums + j].location = i + 1;
            allNums++;
        }
        preNums = allNums;
    }
    for(int i = 0; i < N; i++) {
        locationScoreIndex += krray[i];
        sort(score + preLocationScoreIndex, score + locationScoreIndex, cmp);
        score[preLocationScoreIndex].rankLocation = 1;
        for(int j = preLocationScoreIndex + 1; j < krray[i] + preLocationScoreIndex; j++) {
            if(score[j].score != score[j - 1].score) {
                score[j].rankLocation = j + 1 - preLocationScoreIndex;
            }
            else {
                score[j].rankLocation = score[j - 1].rankLocation;
            }
        }
        preLocationScoreIndex = locationScoreIndex;
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