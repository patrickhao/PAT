#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

typedef struct {
    int id;
    char name[9];
    int grade;
} stu;

bool cmpId(stu m, stu n) {
    return m.id < n.id;
}

bool cmpName(stu m, stu n) {
    int r = strcmp(m.name, n.name);
    if(r == 0) {
        return m.id < n.id;
    }
    else if(r > 0) {
        return false;
    }
    else {
        return true;
    }
}

bool cmpGrade(stu m, stu n) {
    if(m.grade == n.grade) {
        return m.id < n.id;
    }
    else {
        return m.grade < n.grade;
    }
}

int main() {
    freopen("./sample_in/1028.txt", "r", stdin);
    int n, sortWay;
    scanf("%d %d", &n, &sortWay);
    stu* data = (stu*)malloc(n * sizeof(stu));
    for(int i = 0; i < n; i++) {
        scanf("%d %s %d", &data[i].id, &data[i].name, &data[i].grade);
    }
    if(sortWay == 1) {
        sort(data, data + n, cmpId);
    }
    else if(sortWay == 2) {
        sort(data, data + n, cmpName);
    }
    else{
        sort(data, data + n, cmpGrade);
    }
    for(int i = 0; i < n; i++) {
        printf("%06d %s %d\n", data[i].id, data[i].name, data[i].grade);
    }

    return 0;
}