#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
int n, m, k;
bool check[1010][1010];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int bfs(vector<vector<int>> a, int d) {
	check[0][0] = true;
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	int cnt = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n + 1 && ny >= 0 && ny < m + 2) {
				if (!check[nx][ny] && a[nx][ny] <= d) {
					check[nx][ny] = true;
					q.push(make_pair(nx, ny));
					if (a[nx][ny] != 0)
						cnt++;
				}
			}
		}
	}
	return cnt;
}
int main() {
	cin >> n >> m >> k;
	vector<vector<int>> a(n + 1, vector<int>(m + 2, 0));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];
	
	int left = 0, right = 1000000;
	int ans = 1000000;
	while (left <= right) {
		memset(check, false, sizeof(check));
		int mid = (left + right) / 2;
		int res = bfs(a, mid);
		if (res >= k) {
			right = mid - 1;
			ans = min(ans, mid);
		}
		else {
			left = mid + 1;
		}
	}
	cout << ans << '\n';
	
	return 0;
}