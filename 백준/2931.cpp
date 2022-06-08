#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
char a[26][26];
bool check[26][26];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int r, c;
int ex, ey;
char adj[4][4] = {
	{'-','+','3','4'},
	{'-','+','1','2'},
	{'|','+','2','3'},
	{'|','+','1','4'},
};
tuple<int, int, int> get_next(int x, int y, int dir) {
	int nx, ny, ndir;
	if (a[x][y] == '1') {
		if (dir == 1) {
			nx = x + 1;
			ny = y;
			ndir = 2;
		}
		else if (dir == 3) {
			nx = x;
			ny = y + 1;
			ndir = 0;
		}
	}
	else if (a[x][y] == '2') {
		if (dir == 1) {
			nx = x - 1;
			ny = y;
			ndir = 3;
		}
		else if (dir == 2) {
			nx = x;
			ny = y + 1;
			ndir = 0;
		}
	}
	else if (a[x][y] == '3') {
		if (dir == 0) {
			nx = x - 1;
			ny = y;
			ndir = 3;
		}
		else if (dir == 2) {
			nx = x;
			ny = y - 1;
			ndir = 1;
		}
	}
	else if (a[x][y] == '4') {
		if (dir == 0) {
			nx = x + 1;
			ny = y;
			ndir = 2;
		}
		else if (dir == 3) {
			nx = x;
			ny = y - 1;
			ndir = 1;
		}
	}
	return make_tuple(nx, ny, ndir);
}
char block_type(int x, int y) {
	bool dir[4] = { false, };
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
			for (int j = 0; j < 4; j++) {
				if (a[nx][ny] == adj[i][j]) {
					dir[i] = true;
					continue;
				}
			}
		}
	}
	if (!dir[0] && !dir[1] && dir[2] && dir[3]) return '|';
	else if (dir[0] && dir[1] && !dir[2] && !dir[3]) return '-';
	else if (dir[0] && dir[1] && dir[2] && dir[3]) return '+';
	else if (dir[0] && !dir[1] && dir[2] && !dir[3]) return '1';
	else if (dir[0] && !dir[1] && !dir[2] && dir[3]) return '2';
	else if (!dir[0] && dir[1] && !dir[2] && dir[3]) return '3';
	else if (!dir[0] && dir[1] && dir[2] && !dir[3]) return '4';
}
void bfs(int x, int y, int dir) {
	check[x][y] = true;
	queue<tuple<int, int, int>> q;
	q.push(make_tuple(x, y, dir));
	while (!q.empty()) {
		tie(x, y, dir) = q.front();
		q.pop();
		if (a[x][y] == '|' || a[x][y] == '-') {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
				if (check[nx][ny] == false) {
					if (a[nx][ny] == '.') {
						ex = nx; ey = ny;
						return;
					}
					else {
						check[nx][ny] = true;
						q.push(make_tuple(nx, ny, dir));
					}
				}
			}
		}
		else if (a[x][y] == '+') {
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
					if (check[nx][ny] == false) {
						if (a[nx][ny] == '.') {
							ex = nx; ey = ny;
							return;
						}
						else {
							check[nx][ny] = true;
							q.push(make_tuple(nx, ny, i));
						}
					}
				}
			}
		}
		else {	//1, 2, 3, 4
			tuple<int, int, int> next = get_next(x, y, dir);
			int nx, ny, ndir;
			tie(nx, ny, ndir) = next;
			if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
				if (check[nx][ny] == false) {
					if (a[nx][ny] == '.') {
						ex = nx; ey = ny;
						return;
					}
					else {
						check[nx][ny] = true;
						q.push(make_tuple(nx, ny, ndir));
					}
				}
			}
		}
	}
}
int main() {
	cin >> r >> c;
	int mx, my;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'M') {
				mx = i; my = j;
			}
		}
	}

	int sx, sy, dir;
	for (int i = 0; i < 4; i++) {
		int nx = mx + dx[i];
		int ny = my + dy[i];
		for (int j = 0; j < 4; j++) {
			if (a[nx][ny] == adj[i][j]) {
				sx = nx;
				sy = ny;
				dir = i;
			}
		}
	}

	bfs(sx, sy, dir);

	cout << ex + 1 << ' ' << ey + 1 << ' ' << block_type(ex, ey) << '\n';

	return 0;
}