#include <cstdio>
#include <stack>

using namespace std;
const int maxn = 100001;
const int sqr = 317;
int block[sqr] = {0}, table[maxn] = {0};

int peekMedian(int k) {
    int s = 0;
    for (int i = 0; i < sqr; i++) {
        if (s + block[i] >= k) {
            for (int j = i * sqr; j < (i + 1) * sqr; j++) {
                if (s + table[j] >= k) {
                    return j;
                } 
                s += table[j];
            }
        }
        s += block[i];
    }
    return -1;
}

int main() {
    freopen("./sample_in/1057.txt", "r", stdin);
    stack<int> s;
    char op[12];
    int n;
    scanf("%d", &n);
    while (n--) {
        scanf("%s", op);
        if (op[1] == 'o') {
            if (s.empty()) {
                printf("Invalid\n");
            } else {
                int temp = s.top();
                printf("%d\n", temp);
                s.pop();
                block[temp / sqr]--;
                table[temp]--;
            }
        } else if (op[1] == 'e') {
            if (s.empty()) {
                printf("Invalid\n");
            } else {
                int index;
                if (s.size() % 2 == 0) {
                    index = s.size() / 2;
                } else {
                    index = (s.size() + 1) / 2;
                }
                printf("%d\n", peekMedian(index));
            }
        } else if (op[1] == 'u') {
            int temp;
            scanf("%d", &temp);
            s.push(temp);
            block[temp / sqr]++;
            table[temp]++;
        }
    }
    return 0;
}