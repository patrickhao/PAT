#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

typedef struct {
    char id[16];
    int ith;
    int itm;
    int its;
    int oth;
    int otm;
    int ots;
} people;

bool cmp1(people p1, people p2) {
    if(p1.ith != p2.ith) {
        return p1.ith < p2.ith;
    }
    else if(p1.itm != p2.itm) {
        return p1.itm < p2.itm;
    }
    else {
        return p1.its < p2.its;
    }
}

bool cmp2(people p1, people p2) {
    if(p1.oth != p2.oth) {
        return p1.oth > p2.oth;
    }
    else if(p1.otm != p2.otm) {
        return p1.otm > p2.otm;
    }
    else {
        return p1.ots > p2.ots;
    }
}

int main() {
    freopen("./sample_in/1006.txt", "r", stdin);
    int num;
    scanf("%d", &num);
    people* data = (people*)malloc(num * sizeof(people));
    for(int i = 0; i < num; i++) {
        scanf("%s %d:%d:%d %d:%d:%d", &data[i].id, &data[i].ith, &data[i].itm, &data[i].its, &data[i].oth, &data[i].otm, &data[i].ots);
    }
    sort(data, data + num, cmp1);
    printf("%s ", data[0].id);
    sort(data, data + num, cmp2);
    printf("%s", data[0].id);

    return 0;
}