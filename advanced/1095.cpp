#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;
struct elem {
	char id[8];
	int time;
	char sta[4];
} D1[maxn], D2[maxn];
map<string, int> parkTime;
int n, k;

bool cmp1(elem e1, elem e2) {
	if (strcmp(e1.id, e2.id) != 0) {
		return strcmp(e1.id, e2.id) < 0;
	} else {
		return e1.time < e2.time;
	}
}

bool cmp2(elem e1, elem e2) {
	if (e1.time != e2.time) {
		return e1.time < e2.time;
	} else {
		return strcmp(e1.id, e2.id) < 0;
	}
}

int main() {
	freopen("./sample_in/1095.txt", "r", stdin);
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		int h, m, s;
		scanf("%s %d:%d:%d %s", D1[i].id, &h, &m, &s, D1[i].sta);
		D1[i].time = h * 3600 + m * 60 + s;
	}
	sort(D1, D1 + n, cmp1);
	int index = 0, maxTime = -1;
	for (int i = 0; i < n - 1; i++) {
		if (strcmp(D1[i].id, D1[i + 1].id) == 0) {
			if (D1[i].sta[0] == 'i' && D1[i + 1].sta[0] == 'o') {
				D2[index++] = D1[i];
				D2[index++] = D1[i + 1];
				parkTime[D1[i].id] = parkTime[D1[i].id] + D1[i + 1].time - D1[i].time;
				if (parkTime[D1[i].id] > maxTime) {
					maxTime = parkTime[D1[i].id];
				}
				i++;
			}
		}	
	}
	sort(D2, D2 + index, cmp2);
	int carNum = 0, curIndex = 0;
	while (k--) {
		int h, m, s, tempTime;
		scanf("%d:%d:%d", &h, &m, &s);
		tempTime = h * 3600 + m * 60 + s;
		for (; D2[curIndex].time <= tempTime && curIndex < index; curIndex++) {
			if (D2[curIndex].sta[0] == 'i') {
				carNum++;
			} else {
				carNum--;
			}
		}
		printf("%d\n", carNum);
		
	}
	for (auto it = parkTime.begin(); it != parkTime.end(); it++) {
		if (it->second == maxTime) {
			cout << it->first << " ";
		}
	}
	printf("%02d:%02d:%02d\n", maxTime / 3600, (maxTime / 60) % 60, maxTime % 60);

	return 0;
}
