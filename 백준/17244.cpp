#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
char a[51][51];
int d[51][51];
int sx, sy, ex, ey;
int n, m;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int bfs(int x, int y, int des_x, int des_y) {
	memset(d, -1, sizeof(d));
	d[x][y] = 0;
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		if (x == des_x && y == des_y) return d[x][y];
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (d[nx][ny] == -1 && a[nx][ny] != '#') {
					d[nx][ny] = d[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}
int main() {
	cin >> m >> n;
	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'S') {
				sx = i; sy = j;
			}
			else if (a[i][j] == 'X') {
				v.push_back(make_pair(i, j));
			}
			else if (a[i][j] == 'E') {
				ex = i; ey = j;
			}
		}
	}

	if (v.empty()) {
		cout << bfs(sx, sy, ex, ey) << '\n';
		return 0;
	}

	int ans = 987654321;
	do {
		int cnt = 0;
		cnt += bfs(sx, sy, v.front().first, v.front().second);
		for (int i = 0; i < v.size() - 1; i++) {
			cnt += bfs(v[i].first, v[i].second, v[i + 1].first, v[i + 1].second);
		}
		cnt += bfs(v.back().first, v.back().second, ex, ey);
		ans = min(ans, cnt);
	} while (next_permutation(v.begin(), v.end()));
	cout << ans << '\n';

	return 0;
}