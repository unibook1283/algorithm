#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;
char a[50][50];
int d[50][50][2];
int n;
void bfs(int x, int y, int dir, int ex, int ey, int edir) {
	d[x][y][dir] = 0;
	queue<tuple<int, int, int>> q;
	q.push(make_tuple(x, y, dir));
	while (!q.empty()) {
		tie(x, y, dir) = q.front();
		q.pop();
		if (x == ex && y == ey && dir == edir) return;
		if (dir == 0) {
			if (x - 1 >= 0) {
				if (d[x - 1][y][0] == -1) {
					if (a[x - 1][y - 1] != '1' && a[x - 1][y] != '1' && a[x - 1][y + 1] != '1') {
						d[x - 1][y][0] = d[x][y][dir] + 1;
						q.push(make_tuple(x - 1, y, 0));
					}
				}
			}
			if (x + 1 < n) {
				if (d[x + 1][y][0] == -1) {
					if (a[x + 1][y - 1] != '1' && a[x + 1][y] != '1' && a[x + 1][y + 1] != '1') {
						d[x + 1][y][0] = d[x][y][dir] + 1;
						q.push(make_tuple(x + 1, y, 0));
					}
				}
			}
			if (y - 2 >= 0) {
				if (d[x][y - 1][0] == -1) {
					if (a[x][y - 2] != '1') {
						d[x][y - 1][0] = d[x][y][dir] + 1;
						q.push(make_tuple(x, y - 1, 0));
					}
				}
			}
			if (y + 2 < n) {
				if (d[x][y + 1][0] == -1) {
					if (a[x][y + 2] != '1') {
						d[x][y + 1][0] = d[x][y][dir] + 1;
						q.push(make_tuple(x, y + 1, 0));
					}
				}
			}
			if (x - 1 >= 0 && x + 1 < n) {
				if (d[x][y][1] == -1) {
					if (a[x - 1][y - 1] != '1' && a[x - 1][y] != '1' && a[x - 1][y + 1] != '1'
						&& a[x + 1][y - 1] != '1' && a[x + 1][y] != '1' && a[x + 1][y + 1] != '1') {
						d[x][y][1] = d[x][y][dir] + 1;
						q.push(make_tuple(x, y, 1));
					}
				}
			}
		}
		if (dir == 1) {
			if (y - 1 >= 0) {
				if (d[x][y - 1][1] == -1) {
					if (a[x - 1][y - 1] != '1' && a[x][y - 1] != '1' && a[x + 1][y - 1] != '1') {
						d[x][y - 1][1] = d[x][y][dir] + 1;
						q.push(make_tuple(x, y - 1, 1));
					}
				}
			}
			if (y + 1 < n) {
				if (d[x][y + 1][1] == -1) {
					if (a[x - 1][y + 1] != '1' && a[x][y + 1] != '1' && a[x + 1][y + 1] != '1') {
						d[x][y + 1][1] = d[x][y][dir] + 1;
						q.push(make_tuple(x, y + 1, 1));
					}
				}
			}
			if (x - 2 >= 0) {
				if (d[x - 1][y][1] == -1) {
					if (a[x - 2][y] != '1') {
						d[x - 1][y][1] = d[x][y][dir] + 1;
						q.push(make_tuple(x - 1, y, 1));
					}
				}
			}
			if (x + 2 < n) {
				if (d[x + 1][y][1] == -1) {
					if (a[x + 2][y] != '1') {
						d[x + 1][y][1] = d[x][y][dir] + 1;
						q.push(make_tuple(x + 1, y, 1));
					}
				}
			}
			if (y - 1 >= 0 && y + 1 < n) {
				if (d[x][y][0] == -1) {
					if (a[x - 1][y - 1] != '1' && a[x][y - 1] != '1' && a[x + 1][y - 1] != '1'
						&& a[x - 1][y + 1] != '1' && a[x][y + 1] != '1' && a[x + 1][y + 1] != '1') {
						d[x][y][0] = d[x][y][dir] + 1;;
						q.push(make_tuple(x, y, 0));
					}
				}
			}
		}
	}
}
int main() {
	cin >> n;
	int bx = 0;
	int by = 0;
	int ex = 0;
	int ey = 0;
	// x, y: 통나무 중심의 좌표
	int bdir = 1;
	int edir = 1;
	// dir 0 : 가로  1 : 세로
	memset(d, -1, sizeof(d));
	for (int i = 0; i < n; i++) {
		int bty = -1;
		int ety = -1;
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'B') {
				if (bty == i) bdir = 0;
				bty = i;
				bx += i;
				by += j;
			}
			if (a[i][j] == 'E') {
				if (ety == i) edir = 0;
				ety = i;
				ex += i;
				ey += j;
			}
		}
	}
	bx /= 3;
	by /= 3;
	ex /= 3;
	ey /= 3;

	bfs(bx, by, bdir, ex, ey, edir);

	if (d[ex][ey][edir] == -1) cout << 0 << '\n';
	else cout << d[ex][ey][edir] << '\n';;

	return 0;
}