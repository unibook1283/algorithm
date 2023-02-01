#include <iostream>
#include <vector>
using namespace std;
char a[11][11];
int n, m;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int adj_sea_cnt(int x, int y) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
			cnt++;
			continue;
		}
		if (a[nx][ny] == '.')
			cnt++;
	}
	return cnt;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	
	vector<pair<int, int>> v;
	int sx = 20, sy = 20, ex = 0, ey = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 'X') {
				if (adj_sea_cnt(i, j) >= 3) {
					v.push_back(make_pair(i, j));
				}
				else {
					sx = min(sx, i);
					sy = min(sy, j);
					ex = max(ex, i);
					ey = max(ey, j);
				}
			}
		}
	}
	for (int i = 0; i < v.size(); i++) {
		int x = v[i].first;
		int y = v[i].second;
		a[x][y] = '.';
	}
	for (int i = sx; i <= ex; i++) {
		for (int j = sy; j <= ey; j++) {
			cout << a[i][j];
		}
		cout << '\n';
	}

	return 0;
}