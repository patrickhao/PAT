#include <cstdio>

struct data
{
    int elem;
    int used;
}a[5];


int main() {
    freopen("./sample_in/1012.txt", "r", stdin);
    for(int i = 0; i < 5; i++) {
        a[i].elem = 0;
        a[i].used = 0;
    }
    int a1Flag, a3Num, n, temp;
    a3Num = 0;
    a1Flag = 1;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &temp);
        switch(temp % 5) {
            case 0:
                if(temp % 2 == 0) {
                    a[0].elem += temp;
                    a[0].used = 1;
                }
                break;
            case 1:
                a[1].elem += a1Flag * temp;
                a[1].used = 1;
                a1Flag *= -1;
                break;
            case 2:
                a[2].elem++;
                a[2].used = 1;
                break;
            case 3:
                a[3].elem += temp;
                a[3].used = 1;
                a3Num++;
                break;
            case 4:
                if(temp > a[4].elem) {
                    a[4].elem = temp;
                    a[4].used = 1;
                }
                break;
            default:
                break;
        }
    }
    for(int i = 0; i < 4; i++) {
        if(a[i].used == 0) {
            printf("N ");
        }
        else {
            if(i == 3) {
                printf("%.1f ", (double)a[3].elem / (double)a3Num);
            }
            else {
                printf("%d ", a[i].elem);
            }
        }
    }
    if(a[4].used == 0) {
        printf("N");
    }
    else {
        printf("%d", a[4].elem);
    }
    return 0;
}