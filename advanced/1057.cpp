#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int indexS = 0, indexSt = 0, s[100010], st[100010];

int main() {
    freopen("./sample_in/1057.txt", "r", stdin);
    int n, lastelem;
    bool tag = false;
    char input[15] = {0};
    scanf("%d", &n);
    while(n--) {
        scanf("%s", input);
        if(strcmp(input, "Pop") == 0) {
            if(indexS == 0) {
                printf("Invalid\n");
            } else {
                tag = true;
                printf("%d\n", s[indexS - 1]);
                indexS--;
            }
        } else if(strcmp(input, "Push") == 0) {
            tag = true;
            scanf("%d", &s[indexS++]);
        } else if(strcmp(input, "PeekMedian") == 0) {
            if(indexS == 0) {
                printf("Invalid\n");
            } else {
                if(tag) {
                    tag = false;
                    indexSt = 0;
                    for(int i = 0; i < indexS; i++) {
                        st[indexSt++] = s[i];
                    }
                    sort(st, st + indexSt);
                    if(indexSt % 2 == 0) {
                        lastelem = st[(indexSt - 1) / 2];
                    } else {
                        lastelem = st[indexSt / 2];
                    }
                    printf("%d\n", lastelem);
                } else {
                    printf("%d\n", lastelem);
                }
            }
        } else {
            printf("Invalid\n");
        }

    }
    return 0;
}