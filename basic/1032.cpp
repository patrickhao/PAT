#include <cstdio>
#include <cstring>

int main() {
    freopen("./sample_in/1032.txt", "r", stdin);
    int arraySize;
    scanf("%d", &arraySize);
    int score[arraySize];
    memset(score, 0, sizeof(score));
    int maxScoreSum = 0, index = 0;
    for(int i = 0; i < arraySize; i++) {
        int _x, _y;
        scanf("%d%d", &_x, &_y);
        score[_x] += _y;
        if(score[_x] > maxScoreSum) {
            index = _x;
            maxScoreSum = score[_x];
        }
    }
    printf("%d %d", index, score[index]);

    return 0;
}