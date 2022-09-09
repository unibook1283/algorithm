#include <iostream>
#include <queue>
using namespace std;
int a[1001][1001];
int d[1001][1001];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int n, m;
int h, w, sr, sc, fr, fc;
bool is_possible(int x, int y, int dir) {
	if (dir == 0) {
		if (x + h - 1 >= n) return false;
		for (int i = 0; i < h; i++) {
			if (y + w >= m) return false;
			if (a[x + i][y + w] == 1) return false;
		}
	}
	else if (dir == 1) {
		if (x + h - 1 >= n) return false;
		for (int i = 0; i < h; i++) {
			if (y - 1 < 0) return false;
			if (a[x + i][y - 1] == 1) return false;
		}
	}
	else if (dir == 2) {
		if (y + w - 1 >= m) return false;
		for (int i = 0; i < w; i++) {
			if (x + h >= n) return false;
			if (a[x + h][y + i] == 1) return false;
		}
	}
	else if (dir == 3) {
		if (y + w - 1 >= m) return false;
		for (int i = 0; i < w; i++) {
			if (x - 1 < 0) return false;
			if (a[x - 1][y + i] == 1) return false;
		}
	}
	return true;
}
void bfs(int x, int y) {
	d[x][y] = 0;
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		if (x == fr && y == fc) return;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx <= n - h && ny >= 0 && ny <= m - w) {
				if (d[nx][ny] == -1 && is_possible(x, y, i)) {
					d[nx][ny] = d[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			d[i][j] = -1;
		}
	}
	cin >> h >> w >> sr >> sc >> fr >> fc;
	sr--; sc--; fr--; fc--;
	bfs(sr, sc);
	cout << d[fr][fc] << '\n';

	return 0;
}