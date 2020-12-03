#include <cstring>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
const int maxn = 100010;
struct elem {
    char code[9];
    double tScore;
    int score, num, rank;

    elem() {
        fill(code, code + 9, 0);
        tScore = 0.0;
        score = num = rank = 0;
    }
} D[maxn];
map<string, int> mp;
int n, ind = 0;

bool cmp(elem e1, elem e2) {
    if (e1.score != e2.score) {
        return e1.score > e2.score;
    } else if (e1.num != e2.num) {
        return e1.num < e2.num;
    } else {
        return strcmp(e1.code, e2.code) < 0;
    }
}

int getId(char code[]) {
    if (mp.find(code) != mp.end()) {
        return mp[code];
    } else {
        mp[code] = ind++;
        return mp[code];
    }
}

int main() {
    freopen("./sample_in/1141.txt", "r", stdin);
    scanf("%d", &n);
    char temp1[9], temp2[9];
    double score;
    while (n--) {
        scanf("%s %lf %s", temp1, &score, temp2);
        for (int i = 0; i < strlen(temp2); i++) {
            temp2[i] = tolower(temp2[i]);
        }
        int id = getId(temp2);
        strcpy(D[id].code, temp2);
        if (temp1[0] == 'B') {
            D[id].tScore += score / 1.5;
        } else if (temp1[0] == 'A') {
            D[id].tScore += (double)score;
        } else if (temp1[0] == 'T') {
            D[id].tScore += score * 1.5;
        }
        D[id].num++;
    }
    for (int i = 0; i < ind; i++) {
        D[i].score = (int)D[i].tScore;
    }
    sort(D, D + ind, cmp);
    D[0].rank = 1;
    for (int i = 1; i < ind; i++) {
        if(D[i].score == D[i - 1].score) {
            D[i].rank = D[i - 1].rank;
        } else {
            D[i].rank = i + 1;
        }
    }
    printf("%d\n", ind);
    for (int i = 0; i < ind; i++) {
        printf("%d %s %d %d\n", D[i].rank, D[i].code, D[i].score, D[i].num);
    }

    return 0;
}