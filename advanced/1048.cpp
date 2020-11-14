#include <cstdio>
#include <algorithm>

using namespace std;

int c[100010] = {0}, hashTable[100010] = {0};

int main() {
    freopen("./sample_in/1048.txt", "r", stdin);
    int n, target;
    scanf("%d %d", &n, &target);
    for(int i = 0; i < n; i++) {
        scanf("%d", c + i);
        hashTable[c[i]]++;
    }
    sort(c, c + n);
    
    int i = 0, tag = 1;
    for(; i < n; i++) {
        if(hashTable[target - c[i]]) {
            if(target - c[i] > c[i]) {
                tag = 0;
                break;
            } else if(target - c[i] == c[i]) {
                if(hashTable[c[i]] > 1) {
                    tag = 0;
                    break;
                };
            }
        }
    }
    if(tag) {
        printf("No Solution");
    } else {
        printf("%d %d", c[i], target - c[i]);
    }


    return 0;
}