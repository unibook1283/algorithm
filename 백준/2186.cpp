#include <iostream>
#include <cstring>
using namespace std;
char a[101][101];
int d[101][101][81];
string s;
int n, m, k;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int dfs(int x, int y, int index) {
	if (index == s.length()) {
		return 1;
	}
	if (d[x][y][index] != -1) return d[x][y][index];
	d[x][y][index] = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 1; j <= k; j++) {
			int nx = x + j * dx[i];
			int ny = y + j * dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (a[nx][ny] == s[index]) {
					d[x][y][index] += dfs(nx, ny, index + 1);
				}
			}
		}
	}
	return d[x][y][index];
}
int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	cin >> s;
	int ans = 0;
	memset(d, -1, sizeof(d));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == s.front()) {
				ans += dfs(i, j, 1);
			}
		}
	}
	cout << ans << '\n';

	return 0;
}