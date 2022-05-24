#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int d[501][501];
int dx[] = { -2,-2,-1,-1,1,1,2,2 };
int dy[] = { -1,1,-2,2,-2,2,-1,1 };
int n, m;
void bfs(int x, int y) {
	d[x][y] = 0;
	queue<pair<int, int>>q;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
				if (d[nx][ny] == -1) {
					d[nx][ny] = d[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}
int main() {
	cin >> n >> m;
	int x, y;
	cin >> x >> y;
	x--; y--;

	memset(d, -1, sizeof(d));
	bfs(x, y);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		cout << d[a][b] << ' ';
	}
	cout << '\n';

	return 0;
}