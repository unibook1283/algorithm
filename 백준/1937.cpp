#include <iostream>
#include <cstring>
using namespace std;
int a[501][501];
int cache[501][501];
int n;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

// (x,y)에서 시작해서 이동할 수 있는 칸의 수의 최댓값
int dfs(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= n) return 0;
	int& ret = cache[x][y];
	if (ret != -1) return ret;
	ret = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (a[nx][ny] > a[x][y]) {
			ret = max(ret, 1 + dfs(nx, ny));
		}
	}
	return ret;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	memset(cache, -1, sizeof(cache));
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans = max(ans, dfs(i, j));
		}
	}
	cout << ans << '\n';
	
	return 0;
}