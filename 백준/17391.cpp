#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int a[301][301];
int d[301][301];
int dx[] = { 1,0 };
int dy[] = { 0,1 };
int n, m;
int bfs(int x, int y) {
	d[x][y] = 0;
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		if (x == n - 1 && y == m - 1) return d[x][y];
		for (int i = 0; i < 2; i++) {
			for (int dist = 1; dist <= a[x][y]; dist++) {
				int nx = x + dist * dx[i];
				int ny = y + dist * dy[i];
				if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
					if (d[nx][ny] == -1) {
						d[nx][ny] = d[x][y] + 1;
						q.push(make_pair(nx, ny));
					}
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
		}
	}
	memset(d, -1, sizeof(d));
	cout << bfs(0, 0) << '\n';

	return 0;
}