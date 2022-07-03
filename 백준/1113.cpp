#include <stdio.h>
#include <queue>
#include <cstring>
using namespace std;
int a[60][60];
bool check[60][60];
int n, m;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int ans = 0;
void bfs(int x, int y, int height) {
	check[x][y] = true;
	a[x][y]++;
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n + 2 && ny >= 0 && ny < m + 2) {
				if (a[nx][ny] == height && !check[nx][ny]) {
					check[nx][ny] = true;
					a[nx][ny]++;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}
void update_ans(int height) {
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			if (!check[i][j] && a[i][j] == height) {
				ans++;
				a[i][j]++;
			}
		}
	}
}
int main() {
	int maxh = 0;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &a[i][j]);
			maxh = max(maxh, a[i][j]);
		}
	}

	for (int i = 0; i < maxh; i++) {
		memset(check, false, sizeof(check));
		bfs(0, 0, i);
		update_ans(i);
	}
	printf("%d\n", ans);

	return 0;
}