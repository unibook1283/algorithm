#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int a[101][101];
bool check[101][101];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int n;
bool bfs(int mini, int maxi) {
	if (a[0][0] < mini || maxi < a[0][0]) return false;
	memset(check, false, sizeof(check));
	check[0][0] = true;
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (x == n - 1 && y == n - 1) return true;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
				if (!check[nx][ny]) {
					if (mini <= a[nx][ny] && a[nx][ny] <= maxi) {
						check[nx][ny] = true;
						q.push(make_pair(nx, ny));
					}
				}
			}
		}
	}
	return false;
}
bool go(int dif) {
	for (int i = 0; i + dif <= 200; i++) {
		if (bfs(i, i + dif)) return true;
	}
	return false;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	int left = 0, right = 200, ans = 200;
	// (최대-최소)에 대해서 이분탐색
	while (left <= right) {
		int mid = (left + right) / 2;
		check[0][0] = true;
		if (go(mid)) {
			ans = min(ans, mid);
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	cout << ans << '\n';

	return 0;
}
/*
200밖에 안되는데 이분탐색을 쓰네.
그냥 전체 돌리면 시간 걸리나?

왜 내가 dfs로 한 것(시간 초과)보다 이렇게 bfs하는게 더 빠르지
*/