#include <iostream>
using namespace std;
bool check[6][6];
bool valid_move(int x, int y, int a, int b) {
	int dx = x - a;
	int dy = y - b;
	if (dx < 0) dx = -dx;
	if (dy < 0) dy = -dy;
	if (dx * dy != 2) return false;
	if (dx + dy != 3) return false;
	return true;
}
int main() {
	int t = 36;
	int sx, sy; // 시작 좌표
	int px, py;	// 이전 좌표(매번 갱신)
	while (t--) {
		char cx;
		int x, y;
		cin >> cx >> y;
		x = cx - 'A';
		y--;

		if (t != 35) {
			if (!valid_move(x, y, px, py)) {
				cout << "Invalid\n" << '\n';
				return 0;
			}
		}
		else {
			sx = x;
			sy = y;
		}
		px = x;
		py = y;

		check[x][y] = true;
	}
	if (!valid_move(sx, sy, px, py)) {
		cout << "Invalid\n" << '\n';
		return 0;
	}
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (check[i][j] == false) {
				cout << "Invalid\n";
				return 0;
			}
		}
	}
	cout << "Valid\n";

	return 0;
}