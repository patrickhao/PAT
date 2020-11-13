#include <cstdio>
#include <algorithm>

using namespace std;

struct node {
    int ad;
    int data;
    int next;
    int tag;

    node() {
        ad = data = next = tag = 0;
    }
} arr[100010];

bool cmp(node n1, node n2) {
    if(n1.tag == 0 || n2.tag == 0) {
        return n1.tag > n2.tag;
    }
    else {
        return n1.data < n2.data;
    }
}

int main() {
    freopen("./sample_in/1052.txt", "r", stdin);
    int n, p, temp;
    scanf("%d %d", &n, &p);
    while(n--) {
        scanf("%d", &temp);
        arr[temp].ad = temp;
        scanf("%d %d", &arr[temp].data, &arr[temp].next);
    }

    int count = 0;
    while(p != -1) {
        count++;
        arr[p].tag = 1;
        p = arr[p].next;
    }
    sort(arr, arr + 100010, cmp);
    
    if(count == 0) {
        printf("0 -1\n");
    }
    else {
        printf("%d %05d\n", count, arr[0].ad);
        for(int i = 0; i < count - 1; i++) {
            printf("%05d %d %05d\n", arr[i].ad, arr[i].data, arr[i + 1].ad);
        }
        printf("%05d %d -1\n", arr[count - 1].ad, arr[count - 1].data);
    }

    return 0;
}