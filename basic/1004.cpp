#include <cstdio>

typedef struct {
    char name[11];
    char course[11];
    int score;
}score;

int main() {
    freopen("./sample_in/1004.txt", "r", stdin);
    score data[101], ansMax, ansMin;
    ansMax.score = -1;
    ansMin.score = 101;
    int num;
    scanf("%d", &num);
    for(int i = 0; i < num; i++) {
        scanf("%s%s%d", &data[i].name, &data[i].course, &data[i].score);
        if(data[i].score < ansMin.score) {
            ansMin = data[i];
        }
        if(data[i].score > ansMax.score) {
            ansMax = data[i];
        }
    }
    printf("%s %s\n", ansMax.name, ansMax.course);
    printf("%s %s", ansMin.name, ansMin.course);
    return 0;
}