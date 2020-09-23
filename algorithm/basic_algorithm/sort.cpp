#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

struct node {
    int x, y;
}ssd[10];

struct students {
    int score;
    int rank;
}stu[5];


//自定义排序规则，默认排升序
bool cmp(int a, int b){
    return a > b;
}

bool cmpNode1(node a, node b) {
    return a.x > b.x;
}

//x相同时按y的降序
bool cmpNode2(node a, node b) {
    if(a.x != b.x) {
        return a.x > b.x;
    }
    else {
        return a.y > b.y;
    }
}

//按字典序
bool cmpString1(string str1, string str2) {
    return str1 > str2;
}

//按长度
bool cmpString2(string str1, string str2) {
    return str1.length() > str2.length();
}

//char数组的字典序比较方法
bool cmpString3(char str1[], char str2[]) {
    //str1字典序大于str2字典序
    return strcmp(str1, str2) > 0;
}

bool cmpStudents(students stu1, students stu2) {
    return stu1.score > stu2.score;
}

void selectSort(int m[], int length) {
    for(int i = 0; i < length; i++) {
        int index = i;
        for(int j = i + 1; j < length; j++) {
            if(m[j] < m[index]) {
                index = j;
            }
        }
        int temp = m[i];
        m[i] = m[index];
        m[index] = temp;
    }
}

void insertSort(int m[], int length) {
    for(int i = 1; i < length; i++) {
        int temp = m[i], j = i;
        while(j > 0 && temp < m[j - 1]) {
            m[j] = m[j - 1];
            j--;
        }
        m[j] = temp;
    }
}

int main() {
    int array[] = {123, 34, 56, 67, 235, 904, 321};
    /*********sort function*********/
    //selectSort(array, 7);
    //insertSort(array, 7);
    sort(array, array + 7);
    for(int i = 0; i < 7; i++) {
        printf("%d, ", array[i]);
    }
    printf("\n");
    sort(array, array + 7, cmp);
    for(int i = 0; i < 7; i++) {
        printf("%d, ", array[i]);
    }
    printf("\n");
    //分数相同占用一个排位的实现，需要储存时可写进struct
    stu[0].score = 23;
    stu[1].score = 45;
    stu[2].score = 45;
    stu[3].score = 57;
    stu[4].score = 78;
    sort(stu, stu + 5, cmpStudents);
    stu[0].rank = 1;
    for(int i = 1; i < 5; i++) {
        if(stu[i].score != stu[i - 1].score) {
            stu[i].rank = i + 1;
        } else {
            stu[i].rank = stu[i - 1].rank;
        }
    }
    for(int i = 0; i < 5; i++) {
        printf("%d, ", stu[i].rank);
    }
    printf("\n");
    /*********sort for struct*********/
    ssd[0].x = 19;
    ssd[0].y = 34;
    ssd[1].x = 33;
    ssd[1].y = 32;
    ssd[2].x = 45;
    ssd[2].y = 35;
    ssd[3].x = 89;
    ssd[3].y = 32;
    ssd[4].x = 45;
    ssd[4].y = 74;
    printf("cmpNode1\n");
    sort(ssd, ssd + 5, cmpNode1);
    for(int i = 0; i < 5; i++) {
        printf("%d %d\n", ssd[i].x, ssd[i].y);
    }
    printf("\n");
    printf("cmpNode2\n");
    sort(ssd, ssd + 5, cmpNode2);
    for(int i = 0; i < 5; i++) {
        printf("%d %d\n", ssd[i].x, ssd[i].y);
    }
    printf("\n");
    /*********sort for vector*********/
    vector<int> vi;
    vi.push_back(3);
    vi.push_back(1);
    vi.push_back(2);
    //vector中是int，因此仍然使用int的规则
    sort(vi.begin(), vi.end(), cmp);
    for(int i = 0; i < 3; i++) {
        printf("%d, ", vi[i]);
    } 
    printf("\n");
    /*********sort for string*********/
    printf("cmpString1\n");
    string str[3] = {"bbbb", "cc", "aaa"};
    sort(str, str + 3, cmpString1);
    for(int i = 0; i < 3; i++) {
       cout<<str[i]<<endl; 
    }
    printf("cmpString2\n");
    sort(str, str + 3, cmpString2);
    for(int i = 0; i < 3; i++) {
       cout<<str[i]<<endl; 
    }
    
    return 0;
}