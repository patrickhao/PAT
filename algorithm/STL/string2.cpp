#include <iostream>
#include <string>

using namespace std;
int main() {
    string str1 = to_string(123);
    string str2 = to_string(4.5);

    cout << str1 + str2 << endl;

    int a = stoi(str1);
    double b = stod(str2);

    cout << a << endl;
    cout << b << endl;

    //非法输入，截取最前面的数字，直到不是数字为止，若最前面没有数字，运行时会发生错误
    int ib = stoi(str2);
    cout << ib << endl;

    //非法输入, 截取最前面的浮点数，若最前面是小数点，自动在前面补0
    string str3 = "34.2a";
    string str4 = ".94";
    double c = stod(str3);
    double d = stod(str4);
    cout << c << endl;
    cout << d << endl;

    return 0;
}