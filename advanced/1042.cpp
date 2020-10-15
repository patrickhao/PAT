#include <cstdio>

const int MAXNUM = 54;

void shuffle(int* m, int* o) {
    int temp[MAXNUM];
    for(int i = 0; i < MAXNUM; i++) {
        temp[o[i] - 1] = m[i];
    }
    for(int i = 0; i < MAXNUM; i++) {
        m[i] = temp[i];
    }
}

int main() {
    freopen("./sample_in/1042.txt", "r", stdin);
    char cardLetter[5] = {'S', 'H', 'C', 'D', 'J'};
    int num, order[MAXNUM], card[MAXNUM];
    scanf("%d", &num);
    for(int i = 0; i < MAXNUM; i++) {
        scanf("%d", order + i);
    }
    for(int i = 0; i < MAXNUM; i++) {
        card[i] = i;
    }
    for(int i = 0; i < num; i++) {
        shuffle(card, order);
    }
    for(int i = 0; i < MAXNUM - 1; i++) {
        printf("%c%d ", cardLetter[card[i] / 13], card[i] % 13 + 1);
    }
    printf("%c%d", cardLetter[card[MAXNUM - 1] / 13], card[MAXNUM - 1] % 13 + 1);
    return 0;
}