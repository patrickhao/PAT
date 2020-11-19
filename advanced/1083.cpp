#include <cstdio>
#include <algorithm>

using namespace std;

struct elem {
    char name[12];
    char id[12];
    int grade;
};

bool cmp(elem e1, elem e2) {
    return e1.grade > e2.grade;
}

int main() {
    freopen("./sample_in/1083.txt", "r", stdin);
    int n, low, up;
    scanf("%d", &n);
    elem* data = new elem[n];
    for(int i = 0; i < n; i++) {
        scanf("%s %s %d", &data[i].name, &data[i].id, &data[i].grade);
    }
    scanf("%d %d", &low, &up);

    int index = n - 1;
    for(int i = 0; i < n; i++) {
        if(data[i].grade < low || data[i].grade > up) {
            data[i].grade = -1;
            index--;
        }
    }

    if(index > -1) {
        sort(data, data + n, cmp);
        for(int i = 0; i <= index; i++) {
            printf("%s %s\n", data[i].name, data[i].id);
        }
    } else {
        printf("NONE\n");
    }
    return 0;
}