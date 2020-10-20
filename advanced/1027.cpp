#include <cstdio>
#include <cstdlib>

char* convert(int m) {
    int index = 1;
    char* ans = (char*)malloc(3 * sizeof(char));
    ans[0] = ans[1] = '0';
    ans[2] = 0;
    while(m) {
        if(m % 13 >= 10) {
            ans[index] = m % 13 - 10 + 'A';
        }
        else {
            ans[index] = m % 13 + '0';
        }
        index--;
        m /= 13;
    }
    return ans;
}

int main() {
    freopen("./sample_in/1027.txt", "r", stdin);
    int temp;
    printf("#");
    for(int i = 0; i < 3; i++) {
        scanf("%d", &temp);
        printf("%s", convert(temp));
    }
    return 0;
}