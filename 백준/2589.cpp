#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
char a[50][50];
int d[50][50];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int n, m;
int bfs(int x, int y) {
	int maxi = 0;
	d[x][y] = 0;
	queue<pair<int, int>>q;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (a[nx][ny] == 'L' && d[nx][ny] == -1) {
					d[nx][ny] = d[x][y] + 1;
					maxi = max(maxi, d[nx][ny]);
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	return maxi;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 'L') {
				memset(d, -1, sizeof(d));
				int maxi = bfs(i, j);
				ans = max(ans, maxi);
			}
		}
	}
	cout << ans;

	return 0;
}