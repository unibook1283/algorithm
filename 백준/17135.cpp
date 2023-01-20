#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int n, m, D;
int a[20][20];
int map[20][20];
int d[20][20];
int dx[] = { 0,-1,0 };
int dy[] = { -1,0,1 };
void copy_map() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			map[i][j] = a[i][j];
}
void bfs(int x, int y, vector<pair<int, int>>& erase_coord) {
	d[x][y] = 0;
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		if (d[x][y] == D) return;
		for (int i = 0; i < 3; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && ny < m) {
				if (map[nx][ny] == 1) {
					erase_coord.push_back(make_pair(nx, ny));
					return;
				}
				if (d[nx][ny] == -1) {
					d[nx][ny] = d[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}
int kill_enemy(vector<pair<int, int>> v) {
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int i = 0; i < v.size(); i++) {
		int x = v[i].first;
		int y = v[i].second;
		map[x][y] = 0;
	}
	return v.size();
}
void erase_row(int x) {
	for (int i = 0; i < m; i++)
		map[x][i] = 0;
}
int main() {
	cin >> n >> m >> D;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	vector<int> v;
	for (int i = 0; i < m - 3; i++)
		v.push_back(0);
	for (int i = 0; i < 3; i++)
		v.push_back(1);

	int ans = 0;
	do {
		memset(map, 0, sizeof(map));
		copy_map();
		
		int cnt = 0;
		for (int row = n; row > 0; row--) {
			vector<pair<int, int>> erase_coord;
			for (int col = 0; col < m; col++) {
				if (v[col]) {
					memset(d, -1, sizeof(d));
					bfs(row, col, erase_coord);
				}
			}
			cnt += kill_enemy(erase_coord);
			erase_row(row - 1);
		}
		
		ans = max(ans, cnt);
	} while (next_permutation(v.begin(), v.end()));
	cout << ans << '\n';

	return 0;
}