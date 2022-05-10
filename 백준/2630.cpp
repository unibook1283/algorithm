#include <iostream>
using namespace std;
int a[128][128];
int white = 0, blue = 0;
void go(int x, int y, int size) {
	bool zero = true, one = true;
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (a[i][j] == 1) zero = false;
			else if (a[i][j] == 0) one = false;
		}
	}
	if (zero) {
		white++;
		return;
	}
	else if (one) {
		blue++;
		return;
	}
	go(x, y, size / 2);
	go(x + size / 2, y, size / 2);
	go(x, y + size / 2, size / 2);
	go(x + size / 2, y + size / 2, size / 2);
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

	cout << white << '\n' << blue << '\n';

	return 0;
}