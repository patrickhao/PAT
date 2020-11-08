#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

typedef struct {
    char name[9];
    int age;
    int worth;
} elem;

bool cmp(elem m, elem n) {
    if(m.worth != n.worth) {
        return m.worth > n.worth;
    }
    else if(m.age != n.age) {
        return m.age < n.age;
    }
    else {
        return strcmp(m.name, n.name) < 0;
    }
}

int main() {
    freopen("./sample_in/1055.txt", "r", stdin);
    int n, k;
    scanf("%d %d", &n, &k);
    elem* data = (elem*)malloc(n * sizeof(elem));
    for(int i = 0; i < n; i++) {
        scanf("%s %d %d", &data[i].name, &data[i].age, &data[i].worth);
    }
    sort(data, data + n, cmp);
    for(int i = 1; i <= k; i++) {
        int m, amin, amax, count = 0, index = 0;
        scanf("%d %d %d", &m, &amin, &amax);
        printf("Case #%d:\n", i);
        while(count < m && index < n) {
            if(data[index].age >= amin && data[index].age <= amax) {
                printf("%s %d %d\n", data[index].name, data[index].age, data[index].worth);
                count++;
            }
            index++;
        } 
        if(count == 0) {
            printf("None\n");
        }
    }

    return 0;
}