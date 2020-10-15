#include <cstdio>

int main() {
    freopen("./sample_in/1002.txt", "r", stdin);
    double e1[1010] = {0.0}, e2[1010] = {0.0}, e3[1010] = {0.0}, temp2;
    int num, temp1, index = -1, e3Sum = 0;
    scanf("%d", &num);
    for(int i = 0; i < num; i++) {
        scanf("%d%lf", &temp1, &temp2);
        e1[temp1] = temp2;
    }
    scanf("%d", &num);
    for(int i = 0; i < num; i++) {
        scanf("%d%lf", &temp1, &temp2);
        e2[temp1] = temp2;
    }
    for(int i = 0; i < 1010; i++) {
        e3[i] = e1[i] + e2[i];
    }
    for(int i = 0; i < 1010; i++) {
        if(e3[i] != 0) {
            e3Sum++;
        }
    }
    for(int i = 0; i < 1010; i++) {
        if(e3[i] != 0) {
            index = i;
            break;
        }
    }
    if(index == -1) {
        printf("%d", e3Sum);
    }
    else {
        printf("%d ", e3Sum);
    }
    for(int i = 1009; i >= 0; i--) {
        if(i == index) {
            break;
        }
        if(e3[i] != 0) {
            printf("%d %.1f ", i, e3[i]);
        }
    }
    if(index != -1) {
        printf("%d %.1f", index, e3[index]);
    }

    return 0;
}