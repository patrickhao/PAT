#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 270000;
struct node {
    int v;
    int w;
};

struct ansNode {
    int head;
    int num;
};

vector<node> Adj[MAXN];
vector<ansNode> vAns;
vector<int> headLine;
bool vis[MAXN] = {false};
int n, k;
int num, numPerson, timeAll;

bool cmp(ansNode a1, ansNode a2) {
    if(a1.head / 10000 != a2.head / 10000) {
        return a1.head / 10000 < a2.head / 10000;
    } else if(a1.head / 100 % 100 != a2.head / 100 % 100) {
        return a1.head / 100 % 100 < a2.head / 100 % 100;
    } else {
        return a1.head % 10000 < a2.head % 10000;
    }
}

int s2n(char s[]) {
    return (s[2] - 'A') * 10000 + (s[1] - 'A') * 100 + (s[0] - 'A');
}

void pn2s(int n) {
    char ans[3] = {0};
    for(int i = 0; i < 3; i++) {
        ans[i] = n % 100 + 'A';
        n /= 100;
    }
    printf("%s", ans);
}

int findHead() {
    int head, maxv = 0;
    for(int i = 0; i < headLine.size(); i++) {
        int temp = 0;
        for(int j = 0; j < Adj[headLine[i]].size(); j++) {
            temp += Adj[headLine[i]][j].w;
        }
        if(temp > maxv) {
            maxv = temp;
            head = headLine[i];
        }
    }
    return head;
}

void dfs(int u) {
    headLine.push_back(u);
    vis[u] = true;
    for(int i = 0; i < Adj[u].size(); i++) {
        timeAll += Adj[u][i].w;
        if(!vis[Adj[u][i].v]) {
            numPerson++;
            dfs(Adj[u][i].v);
        }
    }
}

void dfsTrave() {
    num = 0;
    for(int i = 0; i < MAXN; i++) {
        if(Adj[i].size() != 0 && !vis[i]) {
            numPerson = 1;
            timeAll = 0;
            headLine.clear();
            dfs(i);
            if(numPerson > 2 && (timeAll / 2) > k) {
                ansNode temp;
                temp.head = findHead();
                temp.num = numPerson;
                vAns.push_back(temp);
                num++;
            }
        }
    }
}

int main() {
    freopen("./sample_in/1034.txt", "r", stdin);
    scanf("%d %d", &n, &k);
    while(n--) {
        char name1[4], name2[4];
        int times, index1, index2;
        bool flag = true;
        scanf("%s %s %d", name1, name2, &times);
        index1 = s2n(name1);
        index2 = s2n(name2);
        for(int i = 0; i < Adj[index1].size(); i++) {
            if(Adj[index1][i].v == index2) {
                flag = false;
                Adj[index1][i].w += times;
                for(int j = 0; j < Adj[index2].size(); j++) {
                    if(Adj[index2][i].v == index1) {
                        Adj[index2][j].w += times;
                        break;
                    }
                }
                break;
            }
        }
        if(flag) {
            node temp;
            temp.v = index2;
            temp.w = times;
            Adj[index1].push_back(temp);
            temp.v = index1;
            Adj[index2].push_back(temp);
        }
    }
    dfsTrave();
    sort(vAns.begin(), vAns.end(), cmp);
    printf("%d\n", num);
    for(int i = 0; i < vAns.size(); i++) {
        pn2s(vAns[i].head);
        printf(" %d\n", vAns[i].num);
    }

    return 0;
}