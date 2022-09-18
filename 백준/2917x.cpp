#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
char a[501][501];
int d[501][501];
int n, m;
int sx, sy, ex, ey;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
void bfs(queue<pair<int, int>> q) {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (d[nx][ny] == -1 && a[nx][ny] != '+') {
					d[nx][ny] = d[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}
int dijkstra() {
	priority_queue<pair<int, pair<int, pair<int, int>>>> pq; // (나무로부터의 거리, 시작점으로부터 거리, x, y)
	pq.push(make_pair(d[sx][sy], make_pair(0, make_pair(sx, sy))));
	while (!pq.empty()) {
		int x = pq.top().second.second.first;
		int y = pq.top().second.second.second;
		int d_from_tree = pq.top().first;
		int d_from_s = pq.top().second.first;
		pq.pop();
		if (x == ex && y == ey) return d_from_s;
		if (d[x][y] == -1) continue;
		d[x][y] = -1;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (d[nx][ny] != -1 && a[nx][ny] != '+') {
					pq.push(make_pair(d[nx][ny], make_pair(d_from_s + 1, make_pair(nx, ny))));
				}
			}
		}
	}
	return 0;
}
int main() {
	memset(d, -1, sizeof(d));
	cin >> n >> m;
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'V') {
				sx = i; sy = j;
			}
			else if (a[i][j] == 'J') {
				ex = i; ey = j;
			}
			else if (a[i][j] == '+') {
				d[i][j] = 0;
				q.push(make_pair(i, j));
			}
		}
	}

	bfs(q);
	cout << dijkstra() << '\n';
	
	return 0;
}