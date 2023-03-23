#include <iostream>
using namespace std;
int map[1001][1001];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
int n, m, k;
int ex = -1, ey;
void go(int x, int y, int dir, int cnt) {
	if (cnt == k) {
		ex = x + 1;
		ey = y + 1;
		return;
	}
	map[x][y] = cnt;
	int nx = x + dx[dir];
	int ny = y + dy[dir];
	if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
		if (map[nx][ny] == 0) {
			go(nx, ny, dir, cnt + 1);
			return;
		}
	}
	// 방향을 바꿔야 되는 경우
	dir = (dir + 1) % 4;
	nx = x + dx[dir];
	ny = y + dy[dir];
	if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
		if (map[nx][ny] == 0) {
			go(nx, ny, dir, cnt + 1);
		}
	}
}
int main() {
	cin >> m >> n >> k;
	go(0, 0, 0, 1);
	if (ex != -1) {
		cout << ey << ' ' << ex << '\n';
	}
	else {
		cout << 0 << '\n';
	}

	return 0;
}