#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
char a[100][100];
int d[100][100];
int sx, sy, ex, ey;
int w, h;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int bfs(int x, int y) {
	d[x][y] = 0;
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			while (1) {
				if (nx == ex && ny == ey) return d[x][y];
				if (nx < 0 || nx >= h || ny < 0 || ny >= w) break;
				if (a[nx][ny] == '*') break;
				if (a[nx][ny] == '.' && d[nx][ny] == -1) {
					d[nx][ny] = d[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
				nx += dx[i];
				ny += dy[i];
			}
		}
	}
}
int main() {
	cin >> w >> h;

	sx = -1;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'C') {
				if (sx == -1) {
					sx = i; sy = j;
				}
				else ex = i; ey = j;
			}
		}
	}

	memset(d, -1, sizeof(d));
	cout << bfs(sx, sy) << '\n';

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << d[i][j] << ' ';
		}
		cout << '\n';
	}

	//cout << d[ex][ey] - 1 << '\n';

	return 0;
}