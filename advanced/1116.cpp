#include <cstdio>
#include <cmath>

using namespace std;
int rank[10010] = {0};
bool checkTable[10010] = {false};

bool isPrime(int n) {
    double s = sqrt(n);
    for (int i = 2; i <= s; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    freopen("./sample_in/1116.txt", "r", stdin);
    int n1, n2;
    scanf("%d", &n1);
    for (int i = 1; i <= n1; i++) {
        int id;
        scanf("%d", &id);
        rank[id] = i;
    }
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        int cid;
        scanf("%d", &cid);
        printf("%04d: ", cid);
        if (rank[cid] == 0) {
            printf("Are you kidding?\n");
        } else {
            if (checkTable[cid]) {
                printf("Checked\n");
            } else {
                checkTable[cid] = true;
                if (rank[cid] == 1) {
                    printf("Mystery Award\n");
                } else if (isPrime(rank[cid])) {
                    printf("Minion\n");
                } else if (rank[cid] != 0) {
                    printf("Chocolate\n");
                }
            }
        }
    } 

    return 0;
}