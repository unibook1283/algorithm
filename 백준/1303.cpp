#include <iostream>
#include <queue>
using namespace std;
char a[101][101];
bool check[101][101];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int n, m;
int bfs(int x, int y) {
	check[x][y] = true;
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	int cnt = 0;
	int color = a[x][y];
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		cnt++;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (!check[nx][ny] && a[nx][ny] == color) {
					check[nx][ny] = true;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	return cnt;
}
int main() {
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	int w = 0, b = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!check[i][j]) {
				int cnt = bfs(i, j);
				if (a[i][j] == 'W') {
					w += cnt * cnt;
				}
				else {
					b += cnt * cnt;
				}
			}
		}
	}
	cout << w << ' ' << b << '\n';


	return 0;
}