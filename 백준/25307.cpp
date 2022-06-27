#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;
int a[2001][2001];
int d[2001][2001];
int md[2001][2001];
int n, m, k;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
void m_bfs(int x, int y) {
	md[x][y] = 0;
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		if (md[x][y] == k) return;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (md[nx][ny] == -1) {
					if (a[nx][ny] == 0 || a[nx][ny] == 2) {
						a[nx][ny] = 1;
					}
					md[nx][ny] = md[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}
int bfs(int x, int y) {
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
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (a[nx][ny] == 2) {
					return d[x][y] + 1;
				}
				if (d[nx][ny] == -1 && a[nx][ny] == 0) {
					d[nx][ny] = d[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	return -1;
}
int main() {
	int sx, sy;
	cin >> n >> m >> k;
	
	vector<pair<int, int>> mane;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 4) {
				sx = i; sy = j;
			}
			if (a[i][j] == 3) {
				mane.push_back(make_pair(i, j));
			}
		}
	}

	for (int i = 0; i < mane.size(); i++) {
		memset(md, -1, sizeof(md));
		m_bfs(mane[i].first, mane[i].second);
	}

	memset(d, -1, sizeof(d));
	cout << bfs(sx, sy) << '\n';

	return 0;
}