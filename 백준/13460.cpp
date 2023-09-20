#include <iostream>
using namespace std;
string a[11];
int ex, ey;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int answer = 11;
void go(int rx, int ry, int bx, int by, int count, int prev_dir) {
	if (count >= answer) return;
	for (int i = 0; i < 4; i++) {
		if (i == prev_dir) continue;
		bool red_goal = false, red_touch_blue = false, blue_goal = false;
		int nrx = rx, nry = ry, nbx = bx, nby = by;
		// 빨간 구슬 이동
		while (1) {
			nrx += dx[i];
			nry += dy[i];
			if (a[nrx][nry] == 'O') {
				red_goal = true;
				break;
			}
			else if (nrx == bx && nry == by) {
				red_touch_blue = true;
				break;
			}
			else if (a[nrx][nry] == '#') {
				nrx -= dx[i];
				nry -= dy[i];
				break;
			}
		}
		// 파란 구슬 이동
		while (1) {
			nbx += dx[i];
			nby += dy[i];
			if (a[nbx][nby] == 'O') {
				blue_goal = true;
				break;
			}
			else if (a[nbx][nby] == '#') {
				nbx -= dx[i];
				nby -= dy[i];
				if (red_touch_blue) {
					nrx = nbx - dx[i];
					nry = nby - dy[i];
				}
				break;
			}
			else if (nbx == nrx && nby == nry) {
				nbx = nrx - dx[i];
				nby = nry - dy[i];
				break;
			}
		}
		if (blue_goal) {
			continue;
		}
		if (red_goal) {
			answer = min(answer, count);
			return;
		}
		go(nrx, nry, nbx, nby, count + 1, i);
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	int rx, ry, bx, by;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 'R') {
				rx = i; ry = j;
			}
			else if (a[i][j] == 'B') {
				bx = i; by = j;
			}
			else if (a[i][j] == 'O') {
				ex = i; ey = j;
			}
		}
	}
	go(rx, ry, bx, by, 1, -1);
	if (answer == 11)
		cout << -1 << '\n';
	else
		cout << answer << '\n';

	return 0;
}