#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int n;
char a[50][50];
int d[50][50];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
void bfs(int x, int y) {
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
			if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
				if (a[nx][ny] == '1') {
					if (d[nx][ny] == -1 || d[nx][ny] > d[x][y]) {
						d[nx][ny] = d[x][y];
						q.push(make_pair(nx, ny));
					}
				}
				else {
					if (d[nx][ny] == -1 || d[nx][ny] > d[x][y] + 1) {
						d[nx][ny] = d[x][y] + 1;
						q.push(make_pair(nx, ny));
					}
				}
			}
		}
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	memset(d, -1, sizeof(d));
	bfs(0, 0);
	cout << d[n - 1][n - 1] << '\n';

	return 0;
}