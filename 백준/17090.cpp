#include <iostream>
using namespace std;
char a[501][501];
bool check[501][501];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
string dch = "LRUD";
int n, m;
int ans = 0;
void dfs(int x, int y) {
	check[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		char nch = dch[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
			if (!check[nx][ny] && a[nx][ny] == nch) {
				check[nx][ny] = true;
				dfs(nx, ny);
				ans++;
			}
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		if (a[i][0] == 'L' && !check[i][0]) {
			ans++;
			dfs(i, 0);
		}
		if (a[i][m - 1] == 'R' && !check[i][m - 1]) {
			ans++;
			dfs(i, m - 1);
		}
	}
	for (int i = 0; i < m; i++) {
		if (a[0][i] == 'U' && !check[0][i]) {
			ans++;
			dfs(0, i);
		}
		if (a[n - 1][i] == 'D' && !check[n - 1][i]) {
			ans++;
			dfs(n - 1, i);
		}
	}

	cout << ans << '\n';

	return 0;
}