#include <cstdio>
#include <cstring>

int main() {
    freopen("./sample_in/1031.txt", "r", stdin);
    int n, index = 0, tempWeight, weight[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
    char tempID[20] = {0}, wrongID[110][20] = {0}, table[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
    scanf("%d", &n);
    while(n--) {
        tempWeight = 0;
        scanf("%s", tempID);
        for(int i = 0; i < 17; i++) {
            tempWeight += ((tempID[i] - '0') * weight[i]);
        }
        tempWeight %= 11;
        if(table[tempWeight] != tempID[17]) {
            strcpy(wrongID[index++], tempID);
        }
    } 
    if(index > 0) {
        for(int i = 0; i < index; i++) {
            printf("%s\n", wrongID[i]);
        }   
    }
    else {
        printf("All passed");
    }
    return 0;
}