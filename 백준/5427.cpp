#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
char a[1001][1001];
int d[1001][1001];
queue<pair<int, int>> q;
int w, h;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int bfs(int sx, int sy) {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (d[x][y] == -1) {
				if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
				if (nx == sx && ny == sy) continue;
				if (d[nx][ny] != -1 && a[nx][ny] == '.') {
					d[nx][ny] = -1;
					q.push(make_pair(nx, ny));
				}
			}
			else {
				if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
					return d[x][y] + 1;
				}
				if (d[nx][ny] == 0 && a[nx][ny] == '.') {
					d[nx][ny] = d[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
			
		}
	}
	return -1;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		memset(d, 0, sizeof(d));
		while (!q.empty()) {
			q.pop();
		}
		cin >> w >> h;
		int sx, sy;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> a[i][j];
				if (a[i][j] == '@') {
					sx = i;
					sy = j;
					q.push(make_pair(i, j));
				}
			}
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (a[i][j] == '*') {
					d[i][j] = -1;
					q.push(make_pair(i, j));
				}
			}
		}
		
		int ans = bfs(sx, sy);
		if (ans == -1) cout << "IMPOSSIBLE" << '\n';
		else cout << ans << '\n';
	}


	return 0;
}

/*
queue¸¦ ¾È ºñ¿öÁà¼­ Çì¸Ì´Ù.
*/