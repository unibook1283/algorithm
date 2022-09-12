#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
char a[301][301];
bool check[301][301];
int n, m;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
bool bfs(int x, int y, vector<pair<int, int>>& v) {
	check[x][y] = true;
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
				if (!check[nx][ny]) {
					check[nx][ny] = true;
					if (a[nx][ny] == '0') {
						q.push(make_pair(nx, ny));
					}
					else if (a[nx][ny] == '1') {
						v.push_back(make_pair(nx, ny));
					}
					else if (a[nx][ny] == '#') return true;
				}
			}
		}
	}
	return false;
}
int main() {
	cin >> n >> m;
	int sx, sy, ex, ey;
	cin >> sx >> sy >> ex >> ey;
	sx--; sy--; ex--; ey--;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	int ans = 0;
	while (1) {
		ans++;
		vector<pair<int, int>> v;
		memset(check, false, sizeof(check));
		if (bfs(sx, sy, v)) break;
		for (int i = 0; i < v.size(); i++) {
			int x = v[i].first;
			int y = v[i].second;
			a[x][y] = '0';
		}
	}
	cout << ans << '\n';

	return 0;
}