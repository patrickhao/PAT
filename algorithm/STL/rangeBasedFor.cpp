#include <iostream>
#include <vector>

using namespace std;

int main() {
    //range-based for
    int arr[4] = {0, 1, 2, 3};
    //仅可输出，不可修改
    for(int i : arr) {
        cout << i << endl;
    }
    //更改arr的值
    for(int &i : arr) {
        i *= 2;
        cout << i << endl;
    }

    vector<int> v(3, 3);
    for(auto i : v) {
        cout << i << endl;
    }

    return 0;
}