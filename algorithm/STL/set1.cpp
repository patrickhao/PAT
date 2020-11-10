#include <cstdio>
#include <set>

using namespace std;

int main() {
    set<int> st;
    st.insert(1);
    st.insert(3);
    st.insert(2);
    st.insert(1);
    st.insert(3);

    //不支持it + 1
    set<int>::iterator it = st.begin();
    for(; it != st.end(); it++) {
        printf("%d ", *it);
    }
    printf("\n");

    //insert
    st.insert(0);
    for(it = st.begin(); it != st.end(); it++) {
        printf("%d ", *it);
    }
    printf("\n");

    //find
    it = st.find(3);
    printf("%d\n", *it);

    //erase
    //大致同vector
    st.erase(0);
    for(it = st.begin(); it != st.end(); it++) {
        printf("%d ", *it);
    }
    printf("\n");
    st.erase(st.find(1), st.find(3));
    for(it = st.begin(); it != st.end(); it++) {
        printf("%d ", *it);
    }
    printf("\n");

    return 0;
}