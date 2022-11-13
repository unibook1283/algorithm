#include <iostream>
#include <cstring>
using namespace std;
int a[1001][1001];
int n, m;
bool check[1001][1001];
int cache[1001][1001][3];
int dx[] = { 0,0,1 };
int dy[] = { -1,1,0 };
int go(int x, int y, int dir) {
	if (x == n - 1 && y == m - 1) return a[x][y];
	int& ret = cache[x][y][dir];
	if (ret != -987654321) return ret;
	for (int i = 0; i < 3; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
			if (!check[nx][ny]) {
				check[nx][ny] = true;
				ret = max(ret, go(nx, ny, i));
				check[nx][ny] = false;
			}
		}
	}
	ret += a[x][y];
	return ret;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			for (int k = 0; k < 3; k++)
				cache[i][j][k] = -987654321;
		}
	}
	check[0][0] = true;
	cout << go(0, 0, 2) << '\n';

	return 0;
}