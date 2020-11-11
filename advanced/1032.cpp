#include <cstdio>

struct node {
    char data;
    int next;
    bool tag;
    
    node() {
        data = '\0';
        next = 0;
        tag = false;
    }
} data[100000];

int main() {
    freopen("./sample_in/1032.txt", "r", stdin);
    int first, second, n, temp;
    scanf("%d %d %d", &first, &second, &n);
    while(n--) {
        scanf("%d", &temp);
        scanf(" %c %d", &data[temp].data, &data[temp].next);
    }
    int cur = second;
    while(cur != -1) {
        data[cur].tag = true;
        cur = data[cur].next;
    }
    cur = first;
    while(cur != -1) {
        if(data[cur].tag) {
            break;
        }
        cur = data[cur].next;
    }
    if(cur != -1) {
        printf("%05d", cur);
    } else {
        printf("-1");
    }
    
    return 0;
}