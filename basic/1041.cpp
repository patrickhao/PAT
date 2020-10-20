#include <cstdio>
#include <cstdlib>

//hash思想，把试机座位号直接作为数组下标，可以直接通过其访问
typedef struct {
    long long id;
    int a;
    int b;
} stu;

int main() {
    freopen("./sample_in/1041.txt", "r", stdin);
    int num1, num2, temp;
    scanf("%d", &num1);
    stu* data = (stu*)malloc(num1 * sizeof(stu));
    for(int i = 0; i < num1; i++) {
        scanf("%lld%d%d", &data[i].id, &data[i].a, &data[i].b);
    }
    scanf("%d", &num2);
    for(int i = 0; i < num2; i++) {
        scanf("%d", &temp);
        for(int j = 0; j < num1; j++) {
            if(data[j].a == temp) {
                printf("%lld %d\n", data[j].id, data[j].b);
                break;
            }
        }
    }
    return 0;
}