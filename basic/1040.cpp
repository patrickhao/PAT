#include <cstdio>
#include <cstdlib>

int main() {
    freopen("./sample_in/1040.txt", "r", stdin);
    int indexA = 0, indexP = 0, indexT = 0, numA = 0, numT = 0, ans = 0;
    char c;
    char* data = (char*)malloc(100010 * sizeof(char));
    while((c = getchar()) != EOF) {
        data[indexA++] = c;
        if(c == 'A') {
            numA++;
        }
    }
    if(numA) {
        int* numP = (int*)malloc(numA * sizeof(int));
        numP[0] = 0;
        for(int i = 0; i < indexA; i++) {
            if(data[i] == 'P') {
                numP[indexP]++;
            }
            else if(data[i] == 'A') {
                indexP++;
                numP[indexP] = numP[indexP - 1];
            }
        }
        indexT = indexP - 1;
        for(int i = indexA - 1; i >= 0; i--) {
            if(data[i] == 'T') {
                numT++;
            }
            else if(data[i] == 'A') {
                ans = (ans + numT * numP[indexT--]) % 1000000007;
            }
        }
        printf("%d", ans);
    }
    else {
        printf("0");
    }
    
    return 0;
}