#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int a[100][70];
bool check[100][70];
bool visited[100][70];
int n, m;
int dx[] = { -1,-1,-1,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,1,-1,0,1 };
bool is_peak(int x, int y) {
	memset(check, false, sizeof(check));
	check[x][y] = true;
	if (visited[x][y]) return false;
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (a[nx][ny] > a[x][y]) return false;
				if (a[nx][ny] == a[x][y] && check[nx][ny] == false) {
					check[nx][ny] = true;
					visited[nx][ny] = true;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	return true;
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
			if (is_peak(i, j)) ans++;
		}
	}
	cout << ans << '\n';

	return 0;
}