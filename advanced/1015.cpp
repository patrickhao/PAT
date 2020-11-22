#include <iostream>

using namespace std;

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

//反向之后化回十进制判断，因为素数的判断要在十进制下
int reverse(int n, int r) {
    int ans = 0;
    while (n) {
        ans = ans * r + n % r;
        n /= r;
    }
    return ans;
}

int main() {
    freopen("./sample_in/1015.txt", "r", stdin);
    int n, r;
    while (true) {
        cin >> n;
        if (n < 0) {
            break;
        }
        cin >> r;
        if (isPrime(reverse(n, r)) && isPrime(n)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
