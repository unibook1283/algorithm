#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int d[200][200];
int r1, c1, r2, c2;
int dx[] = { -2,-2,0,0,2,2 };
int dy[] = { -1,1,-2,2,-1,1 };
int n;
void bfs(int x, int y) {
	d[x][y] = 0;
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		if (x == r2 && y == c2) return;
		for (int i = 0; i < 6; i++) {
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
	cin >> n;
	cin >> r1 >> c1 >> r2 >> c2;

	memset(d, -1, sizeof(d));
	bfs(r1, c1);

	cout << d[r2][c2] << '\n';

	return 0;
}