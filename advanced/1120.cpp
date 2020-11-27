#include <cstdio>

using namespace std;
bool hashTable[1000] = {false};

int cal(int num) {
    int ans = 0;
    while (num) {
        ans = ans + num % 10;
        num /= 10;
    }
    return ans;
}

int main() {
    freopen("./sample_in/1120.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    while (n--) {
        int temp;
        scanf("%d", &temp);
        hashTable[cal(temp)] = true;
    }
    int ans = 0;
    for (int i = 0; i < 1000; i++) {
        if (hashTable[i]) {
            ans++;
        }
    }
    printf("%d\n", ans);
    int on = 0;
    for (int i = 0; i < 1000; i++) {
        if (hashTable[i]) {
            printf("%d", i);
            if (++on < ans) {
                printf(" ");
            }
        }
    }

    return 0;
}