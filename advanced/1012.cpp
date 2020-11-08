#include <cstdio>
#include <algorithm>

using namespace std;

typedef struct {
    int id, c, m, e, a;
    int rank[4];
}grade;

bool cmpa(grade m, grade n) {
    return m.a > n.a;
}

bool cmpc(grade m, grade n) {
    return m.c > n.c;
}

bool cmpm(grade m, grade n) {
    return m.m > n.m;
}

bool cmpe(grade m, grade n) {
    return m.e > n.e;
}

int main() {
    freopen("./sample_in/1012.txt", "r", stdin);
    int n, m, temp;
    char out1[4] = {'A', 'C', 'M', 'E'};
    grade data[2010];
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &data[i].id, &data[i].c, &data[i].m, &data[i].e);
        data[i].a = (data[i].c + data[i].m + data[i].e) / 3; 
    }
    sort(data, data + n, cmpa);
    data[0].rank[0] = 1;
    for(int i = 1; i < n; i++) {
        if(data[i].a == data[i - 1].a) {
            data[i].rank[0] = data[i - 1].rank[0];
        }
        else {
            data[i].rank[0] = i + 1;
        }
    }
    sort(data, data + n, cmpc);
    data[0].rank[1] = 1;
    for(int i = 1; i < n; i++) {
        if(data[i].c == data[i - 1].c) {
            data[i].rank[1] = data[i - 1].rank[1];
        }
        else {
            data[i].rank[1] = i + 1;
        }
    }
    sort(data, data + n, cmpm);
    data[0].rank[2] = 1;
    for(int i = 1; i < n; i++) {
        if(data[i].m == data[i - 1].m) {
            data[i].rank[2] = data[i - 1].rank[2];
        }
        else {
            data[i].rank[2] = i + 1;
        }
    }
    sort(data, data + n, cmpe);
    data[0].rank[3] = 1;
    for(int i = 1; i < n; i++) {
        if(data[i].e == data[i - 1].e) {
            data[i].rank[3] = data[i - 1].rank[3];
        }
        else {
            data[i].rank[3] = i + 1;
        }
    }
    for(int i = 0; i < m; i++) {
        int index1 = -1, index2 = 0, min;
        scanf("%d", &temp);
        for(int j = 0; j < n; j++) {
            if(data[j].id == temp) {
                index1 = j;
            }
        }
        if(index1 == -1) {
            printf("N/A\n");
        }
        else {
            min = data[index1].rank[index2];
            for(int j = 0; j < 4; j++) {
                if(data[index1].rank[j] < min) {
                    min = data[index1].rank[j];
                    index2 = j;
                }
            }
            printf("%d %c\n", min, out1[index2]);
        }
    }

    return 0;
}