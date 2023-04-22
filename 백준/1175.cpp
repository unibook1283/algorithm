#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
int n, m;
pair<int, int> s;
vector<pair<int, int>> c;
char a[51][51];
int d[51][51][4];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
const int INF = 987654321;
vector<pair<int, int>> bfs(int sx, int sy, int ex, int ey, int prev_dir) {
	vector<pair<int, int>> ret;	// 도착했을 때 (거리, 방향)
	queue<pair<pair<int, int>, int>> q;
	q.push({ { sx,sy }, prev_dir });
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int dir = q.front().second;
		q.pop();
		if (x == ex && y == ey) {
			ret.push_back({ d[x][y][dir], dir });
			continue;
		}
		for (int i = 0; i < 4; i++) {
			if (i == dir) continue;
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (a[nx][ny] != '#' && d[nx][ny][i] == -1) {
					if (dir == -1) d[nx][ny][i] = 1;
					else d[nx][ny][i] = d[x][y][dir] + 1;
					q.push({ {nx,ny},i });
				}
			}
		}
	}
	return ret;
}
int get_minimum(vector<pair<int, int>> v) {
	int mini = INF;
	for (pair<int, int> p : v) {
		mini = min(mini, p.first);
	}
	return mini;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'S') {
				s = { i,j };
			}
			else if (a[i][j] == 'C') {
				c.push_back({ i,j });
			}
		}
	}

	int answer = INF;
	for (int i = 0; i < 2; i++) {
		memset(d, -1, sizeof(d));
		memset(d[s.first][s.second], 0, sizeof(d[s.first][s.second]));
		vector<pair<int, int>> res1 = bfs(s.first, s.second, c[i].first, c[i].second, -1);
		if (res1.empty()) continue;
		for (pair<int, int> p : res1) {
			memset(d, -1, sizeof(d));
			d[c[i].first][c[i].second][p.second] = 0;
			vector<pair<int, int>> res2 = bfs(c[i].first, c[i].second, c[1 - i].first, c[1 - i].second, p.second);
			if (res2.empty()) continue;
			int minimum = get_minimum(res2);
			answer = min(answer, p.first + minimum);
		}
	}

	cout << (answer == INF ? -1 : answer) << '\n';

	return 0;
}