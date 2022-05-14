#include <iostream>
using namespace std;
int a[500];
int ans = 0;
int h, w;
int find_highest_of_lows(int sx) {
	int highest = 0;
	int x = -1;
	for (int i = sx + 1; i < w; i++) {
		if (highest < a[i]) {
			highest = a[i];
			x = i;
		}
	}
	return x;
}
int cal_amount(int sx, int ex) {
	int height = a[ex];
	int amount = 0;
	for (int i = sx + 1; i < ex; i++) {
		amount += height - a[i];
	}
	return amount;
}
void go(int sx) {
	int sheight = a[sx];
	int amount = 0;
	int nx = -1;
	for (int i = sx + 1; i < w; i++) {
		if (a[i] >= sheight) {
			ans += amount;
			nx = i;
			break;
		}
		amount += sheight - a[i];
	}

	if (nx == -1) {
		int hol = find_highest_of_lows(sx);
		if (hol == -1) return;
		amount = cal_amount(sx, hol);
		ans += amount;
		go(hol);
		return;
	}

	go(nx);
}
int main() {
	cin >> h >> w;
	for (int i = 0; i < w; i++) {
		cin >> a[i];
	}

	go(0);
	cout << ans << '\n';

	return 0;
}