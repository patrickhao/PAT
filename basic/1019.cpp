#include <cstdio>
#include <algorithm>

using namespace std;

bool cmp(int m, int n) {
    return m > n;
}

void toArr(int m, int* a) {
    for(int i = 0; i < 4; i++) {
        a[i] = m % 10;
        m /= 10;
    }
}

int toInt(int* a, int tag) {
    int ans = 0;
    if(tag) {
        sort(a, a + 4, cmp);
    }
    else {
        sort(a, a + 4);
    }
    for(int i = 0; i < 4; i++) {
        ans = ans * 10 + a[i]; 
    }
    return ans;
}

int main() {
    freopen("./sample_in/1019.txt", "r", stdin);
    int num, a[4] = {0};
    scanf("%d", &num);
    toArr(num, a);
    if(a[0] == a[1] && a[0] == a[2] && a[0] == a[3]) {
        printf("%04d - %04d = 0000\n", num, num);
    }
    else {
        int ans = 0;
        while(ans != 6174) {
            ans = toInt(a, 1) - toInt(a, 0);
            printf("%04d - %04d = %04d\n", toInt(a, 1), toInt(a, 0), ans);
            toArr(ans, a);
        }
    }

    return 0;
}