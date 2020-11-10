#include <iostream>
#include <string>

using namespace std;

int main() {
    string str1 = "0123456";
    string str2 = "abc";

    str1.insert(3, str2);
    cout << str1 << endl;

    str1.insert(str1.end(), str2.begin(), str2.end());
    cout << str1 << endl;

    str1.erase(str1.end() - 1);
    cout << str1 << endl;

    //删除[first, last)
    str1.erase(str1.end() - 2, str1.end());
    cout << str1 << endl;

    //删除(pos, len)
    str1.erase(3, 3);
    cout << str1 << endl;

    //str1.clear();

    string str3 = "123abcdef123abcdef";
    string str4 = "123";

    //返回str4第一次出现的位置
    cout << str3.find(str4) << endl;
    //从str3[6]开始找
    cout << str3.find(str4, 6) << endl;
    //未找到返回string::npos
    if(str2.find(str4) == string::npos) {
        cout << "not found" << endl;
    }

    //替换字串，注意是将整个字串替换进来而非逐位替换
    string str5 = "Maybe you will turn around.";
    string str6 = "will not";
    string str7 = "Surely";

    //str5[10]开始往后的4个长度的字串替换为str6
    str5.replace(10, 4, str6);
    cout << str5 << endl;

    //[it1, it2)范围内的字串替换为str6
    str5.replace(str5.begin(), str5.begin() + 5, str7);
    cout << str5 << endl;

    return 0;
}