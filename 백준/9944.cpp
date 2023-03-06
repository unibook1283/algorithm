#include <iostream>
#include <cstring>
using namespace std;
int n, m;
char a[31][31];
bool check[31][31];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
const int INF = 987654321;
int answer = INF;
bool allVisited() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == '.' && !check[i][j]) return false;
		}
	}
	return true;
}
bool canMove(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < m && a[x][y] == '.' && !check[x][y]) {
		return true;
	}
	return false;
}
void dfs(int x, int y, int cnt) {
	if (cnt >= answer) return;
	bool finish = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (!canMove(nx, ny)) {
			continue;
		}
		check[nx][ny] = true;
		finish = false;
		while (1) {
			nx += dx[i];
			ny += dy[i];
			if (canMove(nx, ny)) {
				check[nx][ny] = true;
			}
			else {
				nx -= dx[i];
				ny -= dy[i];
				break;
			}
		}
		dfs(nx, ny, cnt + 1);
		while (1) {
			if (x == nx && y == ny) break;
			check[nx][ny] = false;
			nx -= dx[i];
			ny -= dy[i];
		}
	}
	if (finish && allVisited()) {
		if (answer == -1 || answer > cnt) {
			answer = cnt;
		}
	}
}
int main() {
	int t = 1;
	while (cin >> n >> m) {
		memset(check, false, sizeof(check));
		answer = INF;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> a[i][j];

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] != '*') {
					check[i][j] = true;
					dfs(i, j, 0);
					check[i][j] = false;
				}
			}
		}
		if (answer == INF) answer = -1;
		cout << "Case " << t << ": " << answer << '\n';
		t++;
	}

	return 0;
}