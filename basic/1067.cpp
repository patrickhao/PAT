#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("./sample_in/1067.txt", "r", stdin);
	string pw, temp;
	int n, num = 0;
	cin >> pw >> n;
	getchar();
	while (true) {
		getline(cin, temp);
		if (temp == "#") {
			break;
		}
		num++;
		if (temp == pw) {
			cout << "Welcome in" << endl;
			break;
		} else {
			cout << "Wrong password: " << temp << endl;
			if (num >= n) {
				cout << "Account locked" << endl;
				break;
			}
		}
	}

	return 0;
}
