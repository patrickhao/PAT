#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

typedef struct {
    char name[6];
    int year;
    int month;
    int day;
} people;

bool cmp(people a, people b) {
    if(a.year != b.year) {
        return a.year > b.year;
    }
    else if(a.month != b.month) {
        return a.month > b.month;
    }
    else {
        return a.day > b.day;
    }
}

int main() {
    freopen("./sample_in/1028.txt", "r", stdin);
    int num, index = 0;
    char name[6] = {0};
    int year, month, day;
    scanf("%d", &num);
    people* data = (people*)malloc(num * sizeof(people));
    for(int i = 0; i < num; i++) {
        scanf("%s", name);
        scanf("%d/%d/%d", &year, &month, &day);
        if((year == 2014 && month == 9 && day > 6) || (year == 2014 && month > 9) || (year > 2014)) {
            continue;
        } 
        if((year == 1814 && month == 9 && day < 6) || (year == 1814 && month < 9) || (year < 1814)) {
            continue;
        }
        strcpy(data[index].name, name);
        data[index].year = year;
        data[index].month = month;
        data[index].day = day;
        index++;
    }
    sort(data, data + index, cmp);
    if(index == 0) {
        printf("0");
    }
    else {
        printf("%d %s %s", index, data[index - 1].name, data[0].name);
    }
    return 0;
}