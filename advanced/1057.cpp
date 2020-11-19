#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    freopen("./sample_in/1057.txt", "r", stdin);
    vector<int> s, st;
    int n, temp;
    char command[12] = {0};
    scanf("%d", &n);
    while(n--) {
        scanf("%s", command);
        if(command[1] == 'u') {
            scanf("%d", &temp);
            s.push_back(temp);
        } else if(command[1] == 'o') {
            if(s.empty()) {
                printf("Invalid\n");
            } else {
                printf("%d\n", s[s.size() - 1]);
                s.pop_back();
            }
        } else if(command[1] == 'e') {
            if(s.empty()) {
                printf("Invalid\n");
            } else {
                st = s;
                sort(st.begin(), st.end());
                if(st.size() % 2 == 0) {
                    printf("%d\n", st[st.size() / 2]);
                } else {
                    printf("%d\n", st[(st.size() + 1) / 2]);
                }
            }
        } else {
            printf("Invalid\n");
        }
    }
    return 0;
}