#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
char a[110][110];
bool check[110][110];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int n, m;
string keys;
int cnt = 0;
bool have_key(char ch) {
	for (char key : keys) {
		if (key - 'a' + 'A' == ch) return true;
	}
	return false;
}
void bfs(int x, int y) {
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
				if (!check[nx][ny] && a[nx][ny] != '*') {
					if ('A' <= a[nx][ny] && a[nx][ny] <= 'Z') {
						if (have_key(a[nx][ny])) {
							check[nx][ny] = true;
							a[nx][ny] = '.';
							q.push(make_pair(nx, ny));
						}
					}
					else if ('a' <= a[nx][ny] && a[nx][ny] <= 'z') {
						keys += a[nx][ny];
						memset(check, false, sizeof(check));
						check[nx][ny] = true;
						a[nx][ny] = '.';
						q.push(make_pair(nx, ny));
					}
					else if (a[nx][ny] == '$') {
						check[nx][ny] = true;
						a[nx][ny] = '.';
						q.push(make_pair(nx, ny));
						cnt++;
					}
					else {
						check[nx][ny] = true;
						q.push(make_pair(nx, ny));
					}
				}
			}
		}
	}
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		cnt = 0;
		cin >> n >> m;
		for (int i = 0; i < n + 2; i++) {
			for (int j = 0; j < m + 2; j++) {
				if (i == 0 || i == n + 1 || j == 0 || j == m + 1) a[i][j] = '.';
				else cin >> a[i][j];
			}
		}
		cin >> keys;

		memset(check, false, sizeof(check));
		bfs(0, 0);
		cout << cnt << '\n';
	}

	return 0;
}