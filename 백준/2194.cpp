#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int map[501][501];
int d[501][501];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int n, m, a, b, k;
int sx, sy, ex, ey;
bool on_obstacle(int nx, int ny) {
	for (int i = nx; i < nx + a; i++) {
		for (int j = ny; j < ny + b; j++) {
			if (map[i][j] == 1) return true;
		}
	}
	return false;
}
void bfs(int x, int y) {
	d[x][y] = 0;
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		if (x == ex && y == ey) return;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx + a - 1 < n && ny >= 0 && ny + b - 1 < m) {
				if (d[nx][ny] == -1 && !on_obstacle(nx, ny)) {
					d[nx][ny] = d[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}
int main() {
	cin >> n >> m >> a >> b >> k;
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		map[x][y] = 1;
	}
	cin >> sx >> sy >> ex >> ey;
	sx--; sy--; ex--; ey--;

	memset(d, -1, sizeof(d));
	bfs(sx, sy);
	cout << d[ex][ey];

	return 0;
}