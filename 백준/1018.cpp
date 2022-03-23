#include <iostream>
using namespace std;
char a[51][51];
char bw[8][8] = {	// string으로 해도 되네.
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'}
};
int count(int x, int y) {
	int bw_diff = 0;
	int wb_diff = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (bw[i][j] != a[x + i][y + j]) bw_diff++;
		}
	}
	return min(bw_diff, 64 - bw_diff);
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	int ans = 987654321;
	for (int i = 0; i < n - 7; i++) {
		for (int j = 0; j < m - 7; j++) {
			ans = min(ans, count(i, j));
		}
	}
	cout << ans;

	return 0;
}