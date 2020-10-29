#include <cstdio>
#include <cstring>

typedef struct {
    char username[11];
    char pwd[11];
} data;

int main() {
    freopen("./sample_in/1035.txt", "r", stdin);
    int oldn, n, flag, modNum = 0;
    char username[11] = {0}, pwd[11] = {0};
    data modArr[1010];
    scanf("%d", &n);
    oldn = n;
    while(n--) {
        flag = 0;
        scanf("%s %s", username, pwd);
        for(int i = 0; i < 11; i++) {
            switch(pwd[i]) {
                case '1':
                    flag = 1;
                    pwd[i] = '@';
                    break;
                case '0':
                    flag = 1;
                    pwd[i] = '%';
                    break;
                case 'l':
                    flag = 1;
                    pwd[i] = 'L';
                    break;
                case 'O':
                    flag = 1;
                    pwd[i] = 'o';
                    break;
                default:
                    break; 
            }
        }
        if(flag) {
            strcpy(modArr[modNum].username, username);
            strcpy(modArr[modNum].pwd, pwd);
            modNum++;
        }
    }
    if(modNum) {
        printf("%d\n", modNum);
        for(int i = 0; i < modNum; i++) {
            printf("%s %s\n", modArr[i].username, modArr[i].pwd);
        }
    }
    else if(oldn == 1){
        printf("There is 1 account and no account is modified\n");
    }
    else {
        printf("There are %d accounts and no account is modified\n", oldn);
    }
    return 0;
}