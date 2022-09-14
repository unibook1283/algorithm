#include <iostream>
using namespace std;
int a[1001][1001];
bool check[1001][1001];
int dir[4];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int n, m, k;
bool end(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
			if (!check[nx][ny] && a[nx][ny] == 0) {
				return false;
			}
		}
	}
	return true;
}
int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		a[x][y] = 1;
	}

	int x, y;
	cin >> x >> y;
	check[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int d;
		cin >> d;
		d--;
		dir[i] = d;
	}

	int d_index = 0;
	while (1) {
		int d = dir[d_index];
		while (1) {
			x += dx[d];
			y += dy[d];
			if (x < 0 || x >= n || y < 0 || y >= m ||
				check[x][y] || a[x][y] == 1) {
				x -= dx[d];
				y -= dy[d];
				d_index = (d_index + 1) % 4;
				break;
			}
			check[x][y] = true;
		}
		if (end(x, y)) break;
	}
	cout << x << ' ' << y << '\n';

	return 0;
}