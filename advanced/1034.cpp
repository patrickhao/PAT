#include <iostream>
#include <string>
#include <map>

using namespace std;

const int MAXN = 2020;
const int INF = 1000000000;

int G[MAXN][MAXN] = {0}, weight[MAXN] = {0};
bool vis[MAXN] = {false};

int n, k, numGang = 0, indexPerson = 0;
map<string, int> Gang;
map<string, int> stringToInt;
map<int, string> intToString;

void dfs(int u, int &headnum, int &num, int &weightAll) {
    vis[u] = true;
    num++;
    if(weight[u] > weight[headnum]) {
        headnum = u;
    }
    for(int v = 0; v < indexPerson; v++) {
        if(G[u][v] > 0) {
            weightAll += G[u][v];
            G[u][v] = G[v][u] = 0;
            if(!vis[v]) {
                dfs(v, headnum, num, weightAll);
            }
        }
    }
}

void dfsTrave() {
    for(int u = 0; u < indexPerson; u++) {
        if(!vis[u]) {
            int headnum = u, num = 0, weightAll = 0;
            dfs(u, headnum, num, weightAll);
            if(num > 2 && weightAll > k) {
                Gang[intToString[headnum]] = num;
            }

        }
    }
}

int change(string str) {
    if(stringToInt.find(str) != stringToInt.end()) {
        return stringToInt[str];
    } else {
        stringToInt[str] = indexPerson;
        intToString[indexPerson] = str;
        return indexPerson++;
    }
}

int main() {
    freopen("./sample_in/1034.txt", "r", stdin);
    cin >> n >> k;
    string str1, str2;
    int w, index1, index2;
    while(n--) {
        cin >> str1 >> str2 >> w;
        index1 = change(str1);
        index2 = change(str2);
        weight[index1] += w;
        weight[index2] += w;
        G[index1][index2] += w;
        G[index2][index1] += w; 
    }
    dfsTrave();
    cout << Gang.size() << endl;
    for(auto it = Gang.begin(); it != Gang.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }

    return 0;
}