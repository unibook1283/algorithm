#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;
char a[51][51];
int check[51][51][4];
int ddx[] = { 0,0,1,-1 };
int ddy[] = { 1,-1,0,0 };
int n, m;
bool c_finish = false, d_finish = false;
int ans = 0;
void bfs(int x, int y, int dir) {
	memset(check, -1, sizeof(check));
	if (dir == -1) {
		for (int i = 0; i < 4; i++) {
			check[x][y][i] = 0;
		}
	}
	else
		check[x][y][dir] = 0;
	queue<tuple<int, int, int>> q;
	q.push(make_tuple(x, y, dir));
	while (!q.empty()) {
		tie(x, y, dir) = q.front();
		q.pop();
		if (a[x][y] == 'C') {
			ans += check[x][y][dir];
			if (d_finish) {
				return;
			}
			c_finish = true;
			a[x][y] = '.';
			bfs(x, y, dir);
			return;
		}
		if (a[x][y] == 'D') {
			ans += check[x][y][dir];
			if (c_finish) {
				return;
			}
			d_finish = true;
			a[x][y] = '.';
			bfs(x, y, dir);
			return;
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + ddx[i];
			int ny = y + ddy[i];
			int ndir = i;
			if (dir == ndir) continue;
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (a[nx][ny] != '#' && check[nx][ny][ndir] == -1) {
					if (dir == -1)
						check[nx][ny][ndir] = 1;
					else 
						check[nx][ny][ndir] = check[x][y][dir] + 1;
					q.push(make_tuple(nx, ny, ndir));
				}
			}
		}
	}
}
int main() {
	int sx, sy;
	cin >> n >> m;
	bool first = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'C') {
				if (!first) {
					a[i][j] = 'D';
				}
				else if (first) {
					first = false;
				}
			}
			else if (a[i][j] == 'S') {
				sx = i; sy = j;
			}
		}
	}
	bfs(sx, sy, -1);
	if (ans == 0) 
		cout << -1 << '\n';
	else
		cout << ans << '\n';

	return 0;
}