#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v1(10);
    cout << v1.size() << endl;

    //resize多的部分直接截断，不足的补0
    vector<int> v2;
    v2.resize(3);
    cout << v2[3] << endl;

    //定义时对v3进行初始化, 默认初始化为0
    vector<int> v3(9, 3);
    cout << v3[0] << endl;

    return 0;
}