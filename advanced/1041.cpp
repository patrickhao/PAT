#include <cstdio>

int ind = 0;
int bets[100010] = {0}, history[100010] = {0};

int main() {
    freopen("./sample_in/1041.txt", "r", stdin);
    int n, temp;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &temp);
        history[ind++] = temp;
        bets[temp]++; 
    }
    int tag = 1;
    for(int i = 0; i < ind; i++) {
        if(bets[history[i]] == 1) {
            printf("%d", history[i]);
            tag = 0;
            break;
        }
    }
    if(tag) {
        printf("None");
    }
    return 0; 
}