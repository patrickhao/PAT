#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int n, k, p;
vector<int> ans, temp;

int vSum(vector<int> v) {
    int ans;
    for (int i : v) {
        ans += i;
    }
    return ans;
}

bool cmp1(int n1, int n2) {
    return n1 > n2;
}

bool cmp2(vector<int> v1, vector<int> v2) {
    int s1 = vSum(v1), s2 = vSum(v2);
    sort(v1.begin(), v1.end(), cmp1);
    sort(v2.begin(), v2.end(), cmp1);
    if (s1 != s2) {
        return s1 > s2;
    } else {
        for (int i = 0; i < v1.size(); i++) {
            if (v1[i] != v2[i]) {
                return v1[i] > v2[i];
            }
        }
    }
    return false;
}

int myPow(int elem, int p) {
    int ans = 1;
    for (int i = 0; i < p; i++) {
        ans *= elem;
    }
    return ans;
}

void dfs(int sum, int pos, int elem) {
    sum += myPow(elem, p);
    if (sum > elem) {
        return;
    } else if (sum == elem) {
        temp.push_back(elem);
        if (pos == k && cmp2(temp, ans)) {
            ans = temp;
        }
        temp.pop_back();
        return;
    }
    temp.push_back(elem);
    for (int i = 1; i * i <= n; i++) {
        dfs(sum, pos + 1, i);
    }
    temp.pop_back();
}

void dfsTrave() {
    for (int i = 0; i * i <= n; i++) {
        dfs(0, 1, i);
    }
}

int main() {
    freopen("./sample_in/1103.txt", "r", stdin);
    scanf("%d %d %d", &n, &k, &p);
    ans.resize(k);
    temp.resize(k);
    dfsTrave();
    printf("%d", ans[1]);
    printf("%d", temp[1]);

    return 0;
}