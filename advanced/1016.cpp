#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

typedef struct {
    int month, day, hour, minute;
} time;

typedef struct {
    char name[21];
    int onIndex;
    int offIndex;
    time online[1000];
    time offline[1000];
} elem;

bool cmpName(elem m, elem n) {
    if(strcmp(m.name, n.name) < 0) {
        return true;
    }
    else {
        return false;
    }
}

bool cmpTime(time m, time n) {
    if(m.day != n.day) {
        return m.day < n.day;
    }
    else if(m.hour != n.hour) {
        return m.hour < n.hour;
    }
    else {
        return m.minute < n.minute;
    }
}

int main() {
    freopen("./sample_in/1016.txt", "r", stdin);
    double chargeDay = 0.0, rate[24] = {0.0};
    int n, rateTemp, nowIndex, tag, index = 0;
    char type[10], name[21];
    time tTemp;
    elem* data = (elem*)malloc(1000 * sizeof(elem));
    for(int i = 0; i < 24; i++) {
        scanf("%d", &rateTemp);
        rate[i] = rateTemp / 100.0;
        chargeDay += (60 * rate[i]);
    }
    scanf("%d", &n);
    while(n--) {
        tag = 1;
        scanf("%s %d:%d:%d:%d %s", name, &tTemp.month, &tTemp.day, &tTemp.hour, &tTemp.minute, type);
        for(int i = 0; i < index; i++) {
            if(strcmp(name, data[i].name) == 0) {
                nowIndex = i;
                tag = 0;
            }
        }
        if(tag) {
            nowIndex = index;
            strcpy(data[nowIndex].name, name);
            index++;
        }
        if(strcmp(type, "on-line") == 0) {
            int onlineIndex = data[nowIndex].onIndex;
            data[nowIndex].onIndex++;
            data[nowIndex].online[onlineIndex] = tTemp;
        }
        else {
            int offlineIndex = data[nowIndex].offIndex;
            data[nowIndex].offIndex++;
            data[nowIndex].offline[offlineIndex] = tTemp;
        }
    }
    sort(data, data + index, cmpName);
    for(int i = 0; i < index; i++) {
        sort(data[i].online, data[i].online + data[i].onIndex, cmpTime);
        sort(data[i].offline, data[i].offline + data[i].offIndex, cmpTime);
    }
    for(int i = 0; i < index; i++) {
        int nextTag, index1 = 0, index2 = 0, nameTag = 1, chargeAllTag = 0;
        double chargeAll = 0.0;
        while(index1 < data[i].onIndex && index2 < data[i].offIndex) {
            if(cmpTime(data[i].online[index1], data[i].offline[index2])) {
                nextTag = 1;
                if(index1 != data[i].onIndex - 1) {
                    if(cmpTime(data[i].online[index1 + 1], data[i].offline[index2])) {
                        index1++;
                        nextTag = 0;
                    }
                }
                if(nextTag) {
                    time on = data[i].online[index1], off = data[i].offline[index2];
                    int timeAll = (off.day * 24 * 60 + off.hour * 60 + off.minute) - (on.day * 24 * 60 + on.hour * 60 + on.minute);
                    double charge = 0.0;
                    if(off.day > on.day) {
                        if(off.day - on.day > 0) {
                            charge += ((off.day - on.day - 1) * chargeDay);
                        }
                        charge += ((60 - on.minute) * rate[on.hour]);
                        for(int j = on.hour + 1; j < 24; j++) {
                            charge += (60 * rate[j]);
                        }
                        charge += (off.minute * rate[off.hour]);
                        for(int j = 0; j < off.hour; j++) {
                            charge += (60 * rate[j]);
                        }
                    }
                    else {
                        if(off.hour > on.hour) {
                            for(int j = on.hour + 1; j < off.hour; j++) {
                                charge += (60 * rate[j]);
                            }
                            charge += ((60 - on.minute) * rate[on.hour]);
                            charge += (off.minute * rate[off.hour]);
                        }
                        else {
                            charge += ((off.minute - on.minute) * rate[on.hour]);
                        }
                    }
                    if(nameTag) {
                        nameTag = 0;
                        chargeAllTag = 1;
                        printf("%s %02d\n", data[i].name, data[i].online[0].month);
                    }
                    printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", on.day, on.hour, on.minute, off.day, off.hour, off.minute, timeAll, charge);
                    chargeAll += charge;
                    index1++;
                    index2++;
                }
            }
            else {
                index2++;
            }
        }
        if(chargeAllTag) {
            printf("Total amount: $%.2f\n", chargeAll);
        }
    }
    return 0;
}