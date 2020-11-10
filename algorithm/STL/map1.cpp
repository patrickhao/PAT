#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    map<string, int> m1;
    //
    m1["z"] = 1;
    m1["b"] = 3;
    m1["a"] = 2;
    m1["s"] = 9;
    //一一对应，键不同值可同
    m1["n"] = 3;
    m1["l"] = 4;
    for(map<string, int>::iterator it = m1.begin(); it != m1.end(); it++) {
        cout << it->first << ", " << it->second << endl;
    }

    //逆序迭代器rbegin返回倒数第一个元素的位置，rend返回第一个元素之前的位置，end表示最后一个数据的下一个位置
    cout << m1.rbegin()->first << ", " << m1.rbegin()->second << endl;

    //erase
    auto it = m1.find("z");
    m1.erase(it);
    m1.erase("b");
    for(map<string, int>::iterator it = m1.begin(); it != m1.end(); it++) {
        cout << it->first << ", " << it->second << endl;
    }

    it = m1.find("s");
    //[it1, it2)
    m1.erase(it, m1.end());
    for(map<string, int>::iterator it = m1.begin(); it != m1.end(); it++) {
        cout << it->first << ", " << it->second << endl;
    }
    
    return 0;
}