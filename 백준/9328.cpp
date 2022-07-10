#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <string>
using namespace std;
bool check[110][110];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int n, m;
string keys;
int ans = 0;
void bfs(int x, int y, vector<vector<char>> &a, queue<pair<int, int>> locked_door[26]) {
	check[x][y] = true;
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
				if (a[nx][ny] == '*') continue;
				if (!check[nx][ny]) {
					check[nx][ny] = true;
					if ('A' <= a[nx][ny] && a[nx][ny] <= 'Z') {
						locked_door[a[nx][ny] - 'A'].push(make_pair(nx, ny));
						continue;
					}
					else if (a[nx][ny] == '$') {
						ans++;
					}
					else if ('a' <= a[nx][ny] && a[nx][ny] <= 'z') {
						keys += a[nx][ny];
					}
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	// 큐가 비면 열쇠로 열 수 있는 문들을 다시 큐에 넣어서 bfs 돌림.
	// 다시 돌리는게 좀 비효율적인가. 다른 방법이 있을까.
	for (char key : keys) {
		char door = key - 'a';
		while (!locked_door[door].empty()) {
			auto p = locked_door[door].front();
			locked_door[door].pop();
			int x = p.first;
			int y = p.second;
			bfs(x, y, a, locked_door);
		}
	}
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		queue<pair<int, int>> locked_door[26];
		memset(check, false, sizeof(check));
		ans = 0;
		/*
		for (int i = 0; i < 26; i++) {
			while (!locked_door[i].empty()) {
				locked_door[i].pop();
			}
		}
		*/

		cin >> n >> m;
		vector<vector<char>> a(n + 2, vector<char>(m + 2, '.'));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> a[i][j];
			}
		}
		cin >> keys;
		if (keys=="0") keys.clear();

		bfs(0, 0, a, locked_door);
		cout << ans << '\n';
	}

	return 0;
}