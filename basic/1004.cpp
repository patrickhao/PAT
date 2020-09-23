#include <cstdio>
#include <cstring>

typedef struct {
    char name[11];
    char course[11];
}score;

int main() {
    freopen("./sample_in/1004.txt", "r", stdin);
    score data[101];
    for(int i = 0; i<101; i++) {
        data[i].name[0] = '\0';
        data[i].course[0] = '\0';
    }

    int temp_score, times, index_of_char, index_of_max, index_of_min;
    char temp_name[11], temp_course[11], c;
    
    scanf("%d", &times);
    getchar();
    for(int i = 0; i<times; i++) {
        for(int i = 0; i < 11; i++) {
            temp_name[i] = '\0';
            temp_course[i] = '\0';
        }
        index_of_char = 0;
        while((c = getchar()) != ' ') {
            temp_name[index_of_char++] = c;
        }
        temp_name[index_of_char] = '\0';
        index_of_char = 0;
        while((c = getchar()) != ' ') {
            temp_course[index_of_char++] = c;
        }
        temp_course[index_of_char] = '\0';
        scanf("%d", &temp_score);
        for(int i = 0; i < strlen(temp_name) + 1; i++){
            data[temp_score].name[i] = temp_name[i];
        }
        for(int i = 0; i < strlen(temp_course) + 1; i++){
            data[temp_score].course[i] = temp_course[i];
        }
        getchar();
    }

    for(int i = 0; i < 101; i++) {
        if(data[i].name[0] != '\0') {
            index_of_min = i;
            break;
        }
    }
    for(int i = 100; i > -1; i--) {
        if(data[i].name[0] != '\0') {
            index_of_max = i;
            break;
        }
    }

    printf("%s %s\n", data[index_of_max].name, data[index_of_max].course);
    printf("%s %s\n", data[index_of_min].name, data[index_of_min].course);
    return 0;
}