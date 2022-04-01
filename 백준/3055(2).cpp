#include <iostream>
#include <queue>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
int w_dist[50][50];
int s_dist[50][50];
queue<pair<int, int>> q;
queue<pair<int, int>> water;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int r, c;
int main() {
	cin >> r >> c;
	vector<string> a(r);
	for (int i = 0; i < r; i++) {
		cin >> a[i];
	}
	int sx, sy;
	int ex, ey;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (a[i][j] == 'S') {
				sx = i;
				sy = j;
			}
			else if (a[i][j] == 'D') {
				ex = i;
				ey = j;
			}
			else if (a[i][j] == '*') water.push(make_pair(i, j));
		}
	}
	memset(w_dist, -1, sizeof(w_dist));
	while (!water.empty()) {
		int x = water.front().first;
		int y = water.front().second;
		water.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
				// a[nx][ny]=='S'는 안해도됨. 어짜피 지나갔으니
				if (a[nx][ny] == 'X') continue;
				if (a[nx][ny] == '.' && w_dist[nx][ny] == -1) {
					w_dist[nx][ny] = w_dist[x][y] + 1;
					water.push(make_pair(nx, ny));
				}
			}
		}
	}
	memset(s_dist, -1, sizeof(s_dist));
	s_dist[sx][sy] = 0;
	q.push(make_pair(sx, sy));
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
				if (a[nx][ny] == 'X') continue;
				if (w_dist[nx][ny] == -1 || s_dist[x][y] < w_dist[nx][ny]) {
					if (a[nx][ny] == '.' || a[nx][ny] == 'D') {
						s_dist[nx][ny] = s_dist[x][y] + 1;
						q.push(make_pair(nx, ny));
					}
				}
			}
		}
	}
	if (s_dist[ex][ey] == -1) cout << "KAKTUS";
	else cout << s_dist[ex][ey];

	return 0;
}