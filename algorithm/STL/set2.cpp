#include <iostream>
#include <set>

using namespace std;

int main() {
    set<int> s1;
    for(int i = 0; i < 6; i++) {
        s1.insert(i);
    }
    //find()未找到返回end位置，找到返回该元素的位置
    cout << *s1.find(3) << endl;
    cout << (s1.find(3) != s1.end()) << endl;

    s1.erase(3);
    cout << (s1.find(3) != s1.end()) << endl;

    return 0;
}