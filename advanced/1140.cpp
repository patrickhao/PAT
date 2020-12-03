#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int maxn = 1000;
vector<int> v1 ,v2;

int main() {
    freopen("./sample_in/1140.txt", "r", stdin);
    int temp, n;
    cin >> temp >> n;
    v1.push_back(temp);
    n--;
    while (n--) {
        v2.clear();
        for (int i = 0; i < v1.size();) {
            int num = 1, a = v1[i];
            i++;
            while (i < v1.size() && v1[i] == a) {
               i++; 
               num++;
            }
            v2.push_back(a);
            v2.push_back(num);
        }
        v1 = v2;
    }
    for (int i : v1) {
        printf("%d", i);
    }
    printf("\n");

    return 0;
}