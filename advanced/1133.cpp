#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int maxn = 100010;
const int INF = 1000000000;
struct node {
    int id;
    int data;
    int nextid;
    int tag;

    node () {
        id = tag = INF;
    }
} List[maxn], List2[maxn];

bool cmp(node n1, node n2) {
    return n1.tag < n2.tag;
}

int main() {
    freopen("./sample_in/1133.txt", "r", stdin);
    int first, n, k, realNum = 0;
    cin >> first >> n >> k;
    for (int i = 0; i < n; i++) {
        int id, data, nextid;
        cin >> id >> data >> nextid;
        List[id].id = id;
        List[id].data = data;
        List[id].nextid = nextid;
    }

    int cur = first;
    int tag = 1;
    while (cur != -1) {
        List[cur].tag = tag;
        tag++;
        cur = List[cur].nextid;
        realNum++;
    }
    sort(List, List + maxn, cmp);
    int index = 0;
    for (int i = 0; i < realNum; i++) {
        if (List[i].data < 0) {
            List2[index++] = List[i];
        }
    }
    for (int i = 0; i < realNum; i++) {
        if (List[i].data >= 0 && List[i].data <= k) {
            List2[index++] = List[i];
        }
    }
    for (int i = 0; i < realNum; i++) {
        if (List[i].data > k) {
            List2[index++] = List[i];
        }
    }
    for (int i = 0; i < realNum; i++) {
        if (i < realNum - 1) {
            printf("%05d %d %05d\n", List2[i].id, List2[i].data, List2[i + 1].id);
        } else {
            printf("%05d %d -1\n", List2[i].id, List2[i].data);
        }
    }

    return 0;
}