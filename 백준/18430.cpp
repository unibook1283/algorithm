#include <iostream>
using namespace std;
int a[5][5];
bool check[5][5];
int n, m;
int answer = 0;
void go(int x, int y, int sum) {
	if (y == m) {
		y = 0;
		x++;
	}
	if (x == n) {
		answer = max(answer, sum);
		return;
	}
	if (!check[x][y]) {
		if (x + 1 < n && y + 1 < m && !check[x + 1][y] && !check[x][y + 1]) {
			check[x][y] = true;
			check[x + 1][y] = true;
			check[x][y + 1] = true;
			int new_sum = sum + 2 * a[x][y] + a[x + 1][y] + a[x][y + 1];
			go(x, y + 1, new_sum);
			check[x][y + 1] = false;
			check[x + 1][y] = false;
			check[x][y] = false;
		}
		if (x + 1 < n && y + 1 < m && !check[x][y + 1] && !check[x + 1][y + 1]) {
			check[x][y] = true;
			check[x][y + 1] = true;
			check[x + 1][y + 1] = true;
			int new_sum = sum + a[x][y] + 2 * a[x][y + 1] + a[x + 1][y + 1];
			go(x, y + 1, new_sum);
			check[x + 1][y + 1] = false;
			check[x][y + 1] = false;
			check[x][y] = false;

		}
		if (x + 1 < n && y + 1 < m && !check[x + 1][y] && !check[x + 1][y + 1]) {
			check[x][y] = true;
			check[x + 1][y] = true;
			check[x + 1][y + 1] = true;
			int new_sum = sum + a[x][y] + 2 * a[x + 1][y] + a[x + 1][y + 1];
			go(x, y + 1, new_sum);
			check[x + 1][y + 1] = false;
			check[x + 1][y] = false;
			check[x][y] = false;

		}
		if (x + 1 < n && y - 1 >= 0 && !check[x + 1][y] && !check[x + 1][y - 1]) {
			check[x][y] = true;
			check[x + 1][y] = true;
			check[x + 1][y - 1] = true;
			int new_sum = sum + a[x][y] + 2 * a[x + 1][y] + a[x + 1][y - 1];
			go(x, y + 1, new_sum);
			check[x + 1][y - 1] = false;
			check[x + 1][y] = false;
			check[x][y] = false;
		}
	}
	go(x, y + 1, sum);
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	go(0, 0, 0);
	cout << answer << '\n';

	return 0;
}