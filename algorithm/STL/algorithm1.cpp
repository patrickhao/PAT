#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int a, b, c;
    a = 9;
    b = 6;
    c = 27;
    cout << max(a, b) << endl;
    cout << max(a, max(b, c)) << endl;

    a = -3;
    //进可用于int，浮点型请用math头文件下的fabs()
    cout << abs(a) << endl;
    double aa = -9.3;
    float bb = -9.234;
    cout << fabs(aa) << endl;
    cout << fabs(bb) << endl;
    
    a = 1;
    b = 2;
    swap(a, b);
    cout << a << ", " << b << endl;

    int arr[5] = {1, 2, 3, 4, 5};
    //反转[it1, it2)， it可以是指针或迭代器
    reverse(arr, arr + 5);
    for(int i : arr) {
        cout << i << endl;
    }

    string str1 = "abcdef";
    reverse(str1.begin(), str1.end());
    for(char c : str1) {
        cout << c << endl;
    }

    //给出一个序列在全排列中的下一个序列，已经到达全排列后返回false
    //由于时下一个序列，注意当前排列不到丢掉
    int brr[3] = {1, 2, 3};
    do {
        for(int i : brr) {
            cout << i << " ";
        } 
        cout << endl;
    }
    while(next_permutation(brr, brr + 3));

    //给数组或容器的某一区间赋相同的值
    int crr[5];
    fill(crr, crr + 5, 233);
    for(int i : crr) {
        cout << i << endl;
    }

    //查找有序容器符合条件值的位置
    //lower_bound(val, first, last)：返回[first, last)第一个值大于等于val的元素的位置，指针或迭代器
    //upper_bound(val, first, last)：返回[first, last)第一个值大于val的元素的位置，指针或迭代器
    //未找到返回可以插入该元素的位置，类比二分查找
    int drr[10] = {1, 2, 2, 3, 3, 3, 5, 5, 5 ,5};
    int* lowerPos = lower_bound(drr, drr + 10, -1);
    int* upperPos = upper_bound(drr, drr + 10, -1);
    cout << lowerPos - drr << ", " << upperPos - drr << endl;

    lowerPos = lower_bound(drr, drr + 10, 1);
    upperPos = upper_bound(drr, drr + 10, 1);
    cout << lowerPos - drr << ", " << upperPos - drr << endl;

    lowerPos = lower_bound(drr, drr + 10, 4);
    upperPos = upper_bound(drr, drr + 10, 4);
    cout << lowerPos - drr << ", " << upperPos - drr << endl;

    lowerPos = lower_bound(drr, drr + 10, 6);
    upperPos = upper_bound(drr, drr + 10, 6);
    //错误写法
    cout << *lowerPos << ", " << *upperPos << endl;
    //更合适的写法，否则会出现上面的问题
    cout << lowerPos - drr << ", " << upperPos - drr << endl;

    //想要查询某元素的下标，可以不使用临时指针，直接令返回值减去数组首地址即可
    cout << "find 3 in drr: ";
    cout << lower_bound(drr, drr + 10, 3) - drr << ", " << upper_bound(drr, drr + 10, 3) - drr << endl;

    return 0;
}