#include <cstdio>

int main() {
    freopen("./sample_in/1061.txt", "r", stdin);
    int day = 0, h, m, flag = 0;
    char t1[80] = {0}, t2[80] = {0}, dayTable[7][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    scanf("%s %s", t1, t2);
    for(int i = 0; i < 80; i++) {
        if((t1[i] == t2[i]) && t1[i] >= 'A' && t1[i] <= 'G' && flag == 0) {
            day = t1[i] - 'A';
            flag = 1;
            continue;
        }
        if((t1[i] == t2[i]) && flag == 1) {
            if(t1[i] >= 'A' && t1[i] <= 'N') {
                h = t1[i] - 'A' + 10;
                break;
            }
            else if(t1[i] >= '0' && t1[i] <= '9') {
                h = t1[i] - '0';
                break;
            }
        }
    }
    scanf("%s %s", t1, t2);
    for(int i = 0; i < 80; i++) {
        if(t1[i] == t2[i]) {
            if((t1[i] >= 'a' && t1[i] <= 'z') || (t1[i] >= 'A' && t1[i] <= 'Z')) {
                m = i;
                break;
            }
        }
    }
    printf("%s %02d:%02d", dayTable[day], h, m);
    return 0;
}