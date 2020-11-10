#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct fruit {
    string name;
    int price;
    //price大的优先级高，不可重载>，要改变优先级更改函数内的符号即可
    friend bool operator < (fruit f1, fruit f2) {
        return f1.price < f2.price;
    }
};

//price大的优先级高
struct cmp {
    bool operator () (fruit f1, fruit f2){
        return f1.price > f2.price;
    }
};

//priority_queue
int main() {
    priority_queue<int> q;
    q.push(3);
    q.push(5);
    q.push(4);
    //与queue不同，只能通过top访问队首元素
    cout << q.top() << endl;

    //元素优先级设置
    //基本数据类型的优先级
    priority_queue<int> q1;
    //等价于，注意less后的<>与最后一个>之间加一个空格，否则编译器容易识别成位运算报错
    //数值大的优先级高
    priority_queue<int, vector<int>, less<int> > q2;
    
    //数值小的优先级高
    priority_queue<int, vector<int>, greater<int> > q3;

    //结构体的优先级设置
    //方法一
    priority_queue<fruit> q4;
    //方法二
    priority_queue<fruit, vector<fruit>, cmp> q5;

    return 0;
}