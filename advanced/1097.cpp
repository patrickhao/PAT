#include <cstdio>
#include <cmath>

using namespace std;

struct node {
    int val;
    int next;
} List[100010];

void putList(int head) {
    int h = head;
    while (h != -1) {
        if (List[h].next == -1) {
            printf("%.5d %d %d\n", h, List[h].val, List[h].next);
        } else {
            printf("%.5d %d %.5d\n", h, List[h].val, List[h].next);
        }
        h = List[h].next;
    }
}

int main() {
    freopen("./sample_in/1097.txt", "r", stdin);
    bool hashTable[10010] = {false};
    int n, head;
    scanf("%d %d", &head, &n);
    for (int i = 0; i < n; i++) {
        int ad;
        node temp;
        scanf("%d %d %d", &ad, &temp.val, &temp.next);
        List[ad] = temp;
    }

    int cur, pre, index;
    int nHead, nTail;
    cur = pre = head;
    nHead = nTail = -1;
    hashTable[index] = true;
    cur = List[cur].next;
    while (cur != -1) {
        index = abs(List[cur].val);
        int tNext = List[cur].next;
        if (hashTable[index]) {
            List[pre].next = List[cur].next;
            if (nHead == -1) {
                nTail = nHead = cur;
                List[nTail].next = -1;
            } else {
                List[nTail].next = cur;
                nTail = cur;
                List[nTail].next = -1;
            }
        } else {
            hashTable[index] = true;
            pre = cur;
        }
        cur = tNext;
    }
    putList(head);
    putList(nHead);

    return 0;
}