#include <cstdio>

int whoWin(char m, char n) {
    if(m == 'B' && n == 'C') {
        return 0;
    }
    else if(m == 'B' && n =='J') {
        return 1;
    }
    else if(m == 'C' && n == 'B') {
        return 1;
    }
    else if(m == 'C' && n == 'J') {
        return 0;
    }
    else if(m == 'J' && n == 'B') {
        return 0;
    }
    else if(m == 'J' && n == 'C') {
        return 1;
    }
    else {
        return -1;
    }
}

char highChar(int* c) {
    if(c['B'] >= c['C']) {
        if(c['B'] >= c['J']) {
            return 'B';
        }
        else {
            return 'J';
        }
    }
    else {
        if(c['C'] >= c['J']) {
            return 'C';
        }
        else {
            return 'J';
        }
    }
}

int main() {
    freopen("./sample_in/1018.txt", "r", stdin);
    int num, aw = 0, ad = 0, al = 0;
    int aWin['J' + 1] = {0}, bWin['J' + 1] = {0};
    scanf("%d", &num);
    getchar();
    for(int i = 0; i < num; i++) {
        char c[2] = {0};
        int result;
        scanf("%c %c \n", &c[0], &c[1]);
        result = whoWin(c[0], c[1]);
        switch (result) {
        case -1:
            ad++;
            break;
        case 0:
            aw++;
            aWin[c[0]]++;
            break;
        case 1:
            al++;
            bWin[c[1]]++;
            break;
        default:
            break;
        }
    }
    printf("%d %d %d\n", aw, ad, al);
    printf("%d %d %d\n", al, ad, aw);
    printf("%c %c", highChar(aWin), highChar(bWin));
    return 0;
}