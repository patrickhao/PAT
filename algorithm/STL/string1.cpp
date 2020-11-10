#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string str = "abc";
    //用cout和cin输入和输出
    //cin按空格分隔，需要读入一行用getline()
    //getline(cin, str);
    //cin >> str;
    //cout << str << endl;
    cout << str << endl;
    //用printf输出
    printf("%s\n", str.c_str());

    //string operate +/-
    string str1 = "abc";
    string str2 = "xyz";
    cout << str1 + str2 << endl;

    //string operate compare
    if(str1 < str2) {
        printf("ok\n");
    }

    //迭代器访问
    string::iterator it = str.begin();
    for(; it != str.end(); it++) {
        cout << *it << endl;
    }

    //substr
    string str3 = "Good morning, Princess!";
    //从str3[14]开始截取
    cout << str3.substr(14) << endl;
    //从str3[5]开始，截取7个字符
    cout << str3.substr(5, 7) << endl;

    return 0;
}