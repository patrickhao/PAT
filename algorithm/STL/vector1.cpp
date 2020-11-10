#include <cstdio>
#include <vector>

using namespace std;

int main() {
    vector<int> vi;
    for(int i = 0; i < 5; i++) {
        vi.push_back(i);
    }
    //solution1
    for(int i = 0; i < 5; i++) {
        printf("%d ", vi[i]);
    }
    printf("\n");
    //solution2
    vector<int>::iterator it = vi.begin();
    for(int i = 0; i < 5; i++) {
        printf("%d ", *(it + i));
    }
    printf("\n");
    //solution3
    for(; it != vi.end(); it++) {
        printf("%d ", *it);
    }
    printf("\n");

    //size
    printf("size: %u\n", vi.size());

    //insert(it, x)
    vi.insert(vi.begin() + 2, -1);
    for(int i = 0; i < vi.size(); i++) {
        printf("%d ", vi[i]);
    }
    printf("\n");

    //erase(it)
    vi.erase(vi.begin() + 2);
    for(int i = 0; i < vi.size(); i++) {
        printf("%d ", vi[i]);
    }
    printf("\n");
    //erase(first, lase) [first, lase)
    vi.erase(vi.begin(), vi.begin() + 3); //delete v[0], v[1], v[2]
    for(int i = 0; i < vi.size(); i++) {
        printf("%d ", vi[i]);
    }
    printf("\n");

    //clear
    vi.clear();
    //vi.erase(vi.begin(), vi.end());
    printf("size: %u\n", vi.size());
    
    return 0;
}