#include <iostream>
using namespace std;
char a[10001][10001];
bool check[10001][10001];
int dx[] = { -1,0,1 };
int dy = 1;
int n, m;
bool dfs(int x, int y) {
	check[x][y] = true;
	for (int i = 0; i < 3; i++) {
		int nx = x + dx[i];
		int ny = y + dy;
		if (ny == m - 1) return true;
		if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
			if (!check[nx][ny] && a[nx][ny] == '.') {
				check[nx][ny] = true;
				if (dfs(nx, ny)) return true;
			}
		}
	}
	return false;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (dfs(i, 0)) ans++;
	}
	cout << ans << '\n';

	return 0;
}