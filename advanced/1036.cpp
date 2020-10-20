#include <cstdio>
#include <cstdlib>

typedef struct {
    char name[11];
    char gender;
    char id[11];
    int grade;
} people;

int main() {
    freopen("./sample_in/1036.txt", "r", stdin);
    int num, maxf = -1, findex = -1, minm = 101, mindex = -1;
    scanf("%d", &num);
    people* data = (people*)malloc(num * sizeof(people));
    for(int i = 0; i < num; i++) {
        scanf("%s %c %s %d", &data[i].name, &data[i].gender, &data[i].id, &data[i].grade);
    }
    for(int i = 0; i < num; i++) {
        if(data[i].gender == 'F') {
            if(data[i].grade > maxf) {
                maxf = data[i].grade;
                findex = i;
            }
        }
        if(data[i].gender == 'M') {
            if(data[i].grade < minm) {
                minm = data[i].grade;
                mindex = i;
            }
        }
    }
    if(findex != -1) {
        printf("%s %s\n", data[findex].name, data[findex].id);
    }
    else {
        printf("Absent\n");
    }
    if(mindex != -1) {
        printf("%s %s\n", data[mindex].name, data[mindex].id);
    }
    else {
        printf("Absent\n");
    }
    if(findex != -1 && mindex != -1) {
        printf("%d", maxf - minm);
    }
    else {
        printf("NA");
    }

    return 0;
}