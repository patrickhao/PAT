#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
    
vector<int> ans[2510];
char name[40010][5];

bool cmp(int a, int b) {
    return strcmp(name[a], name[b]) < 0;
}

int main() {
    freopen("./sample_in/1047.txt", "r", stdin);
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%s", name[i]);
        scanf("%d", &num);
        while (num--) {
            int index;
            scanf("%d", &index);
            ans[index].push_back(i);
        }
    }
    for (int i = 1; i <= k; i++) {
        printf("%d %d\n", i, ans[i].size());
        sort(ans[i].begin(), ans[i].end(), cmp);
        for (int j = 0; j < ans[i].size(); j++) {
            printf("%s\n", name[ans[i][j]]);
        }
    }

    return 0;
}