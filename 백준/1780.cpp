#include <iostream>
using namespace std;
int a[3 * 3 * 3 * 3 * 3 * 3 * 3][3 * 3 * 3 * 3 * 3 * 3 * 3];
int cnt[3] = { 0, };
// 0: -1, 1: 0, 2: 1
void go(int x, int y, int size) {
	bool color[3] = { true,true,true };
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (a[i][j] == -1) {
				color[1] = color[2] = false;
			}
			else if (a[i][j] == 0) {
				color[0] = color[2] = false;
			}
			else {
				color[0] = color[1] = false;
			}
		}
	}
	for (int i = 0; i < 3; i++) {
		if (color[i] == true) {
			cnt[i]++;
			return;
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			go(x + i * size / 3, y + j * size / 3, size / 3);
		}
	}
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	go(0, 0, n);
	for (int i = 0; i < 3; i++) {
		cout << cnt[i] << '\n';
	}

	return 0;
}