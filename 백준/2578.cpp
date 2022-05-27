#include <iostream>
using namespace std;
int a[5][5];
bool d[5][5];
void erase(int n) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (a[i][j] == n) {
				d[i][j] = true;
				return;
			}
		}
	}
}
int bingo() {
	int cnt = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (d[i][j] == false) break;
			if (j == 4) cnt++;
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (d[j][i] == false) break;
			if (j == 4) cnt++;
		}
	}
	for (int i = 0; i < 5; i++) {
		if (d[i][i] == false) break;
		if (i == 4) cnt++;
	}
	for (int i = 0; i < 5; i++) {
		if (d[i][4 - i] == false) break;
		if (i == 4) cnt++;
	}
	return cnt;
}
int main() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 1; i <= 25; i++) {
		int n;
		cin >> n;
		erase(n);

		if (bingo() >= 3) {
			cout << i << '\n';
			break;
		}
	}

	return 0;
}