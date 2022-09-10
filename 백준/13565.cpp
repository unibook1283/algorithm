#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;
int a[1001][1001];
bool check[1001][1001];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int n, m;
bool bfs(queue<pair<int, int>> q) {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (x == n - 1 && a[x][y] == 0) return true;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (!check[nx][ny] && a[nx][ny] == 0) {
					check[nx][ny] = true;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	return false;
}
int main() {
	scanf("%d%d", &n, &m);
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &a[i][j]);
			if (i == 0 && a[i][j] == 0) {
				check[i][j] = true;
				q.push(make_pair(i, j));
			}
		}
	}

	if (bfs(q)) printf("YES\n");
	else printf("NO\n");

	return 0;
}