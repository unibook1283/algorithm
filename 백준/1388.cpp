#include <iostream>
#include <queue>
using namespace std;
int n, m;
char a[50][50];
bool check[50][50];
int dx[] = { 0,1 };
int dy[] = { 1,0 };
int ans = 0;
void bfs(int x, int y) {
	ans++;
	check[x][y] = true;
	char vh = a[x][y];
	int index = 0;
	if (a[x][y] == '|') index = 1;
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		int nx = x + dx[index];
		int ny = y + dy[index];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
			if (a[nx][ny] == vh && check[nx][ny] == false) {
				check[nx][ny] = true;
				q.push(make_pair(nx, ny));
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
		for (int j = 0; j < m; j++) {
			if (check[i][j]==false) bfs(i, j);
		}
	}
	cout << ans << '\n';

	return 0;
}