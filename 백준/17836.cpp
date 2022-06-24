#include <iostream>
#include <queue>
using namespace std;
int a[101][101];
int d[101][101];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int n, m, t;
int bfs(int x, int y) {
	int gram_distance = 987654321;
	d[x][y] = 0;
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		if (a[x][y] == 2) {
			gram_distance = d[x][y] + (n - x - 1) + (m - y - 1);
		}
		if (x == n - 1 && y == m - 1) {
			return min(gram_distance, d[x][y]);
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (a[nx][ny] != 1 && d[nx][ny] == -1) {
					d[nx][ny] = d[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	return gram_distance;
}
int main() {
	cin >> n >> m >> t;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			d[i][j] = -1;
		}
	}

	int res = bfs(0, 0);
	if (res <= t) cout << res << '\n';
	else cout << "Fail\n";
	
	return 0;
}