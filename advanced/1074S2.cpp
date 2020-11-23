#include <cstdio>
#include <vector>

using namespace std;

struct node {
    int val;
    int next;
} List[100010];

int reverse(int head, int k) {
    vector<int> path;
    int curIndex = head, tail;
    for (int i = 0; i < k; i++) {
        if (i != k - 1) {
            path.push_back(curIndex); 
        } else {
            tail = curIndex;
        }
        curIndex = List[curIndex].next;
    }
    curIndex = List[head].next;
    List[head].next = List[tail].next;
    for (int i = 0; i < k - 1; i++) {
        int tNextIndex = List[curIndex].next;
        List[curIndex].next = path[i];
        curIndex = tNextIndex;
    }
    return tail;
}

int findTail(int head, int k) {
    int ans = head;
    for (int i = 0; i < k - 1; i++) {
        ans = List[ans].next;
    }
    return ans;
}

void putList(int root) {
    int cur = root;
    while (cur != -1) {
        if (List[cur].next != -1) {
            printf("%.5d %d %.5d\n", cur, List[cur].val, List[cur].next);
        } else {
            printf("%.5d %d %d\n", cur, List[cur].val, List[cur].next);
        }
        cur = List[cur].next;
    }
}

int main() {
    freopen("./sample_in/1074.txt", "r", stdin);
    int n, k;
    int root;
    scanf("%d %d %d", &root, &n, &k);
    for (int i = 0; i < n; i++) {
        int ad;
        node temp;
        scanf("%d %d %d", &ad, &temp.val, &temp.next);
        List[ad] = temp;
    }
    //统计真实长度
    int p = root;
    n = 0;
    while (p != -1) {
        p = List[p].next;
        n++;
    }
    int cur, newHead, preTail;
    cur = newHead = root;
    for (int i = 0; i < n / k; i++) {
        int r = reverse(cur, k);
        if (i == 0) {
            newHead = r;
        } else {
            List[preTail].next = r;
        }
        preTail = findTail(r, k);
        cur = List[cur].next;
    }
    if (k > 0) {
        List[preTail].next = cur;
    }

    putList(newHead);

    return 0;
}