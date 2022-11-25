#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int a[101][101];
int d[101][101];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int n, m, o, f, sx, sy, ex, ey;
bool bfs(int x, int y) {
	d[x][y] = 0;
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		if (x == ex && y == ey) return true;
		int cur_f = f - d[x][y];
		if (cur_f <= 0) continue;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (d[nx][ny] == -1) {
					if (a[nx][ny] - a[x][y] <= cur_f) {
						d[nx][ny] = d[x][y] + 1;
						q.push(make_pair(nx, ny));
					}
				}
			}
		}
	}
	return false;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		memset(a, 0, sizeof(a));
		memset(d, -1, sizeof(d));
		cin >> n >> m >> o >> f >> sx >> sy >> ex >> ey;
		sx--; sy--; ex--; ey--;
		for (int i = 0; i < o; i++) {
			int x, y, l;
			cin >> x >> y >> l;
			x--; y--;
			a[x][y] = l;
		}
		if (bfs(sx, sy)) cout << "잘했어!!\n";
		else cout << "인성 문제있어??\n";
	}

	return 0;
}