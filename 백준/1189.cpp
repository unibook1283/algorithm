#include <iostream>
#include <cstring>
using namespace std;
char a[5][5];
int d[5][5];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int r, c, k;
int cnt = 0;
void dfs(int x, int y) {
	if (x == 0 && y == c - 1) {
		if (d[x][y] == k - 1) cnt++;
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
			if (a[nx][ny] == 'T') continue;
			if (d[nx][ny] == -1) {
				d[nx][ny] = d[x][y] + 1;
				dfs(nx, ny);
				d[nx][ny] = -1;
			}
		}
	}
}
int main() {
	cin >> r >> c >> k;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> a[i][j];
		}
	}
	memset(d, -1, sizeof(d));
	d[r - 1][0] = 0;

	dfs(r - 1, 0);
	cout << cnt << '\n';

	return 0;
}