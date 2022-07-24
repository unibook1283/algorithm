#include <iostream>
#include <queue>
using namespace std;
char a[251][251];
bool check[251][251];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int n, m;
int wolf = 0, sheep = 0;
void bfs(int x, int y) {
	int  v = 0, k = 0;
	check[x][y] = true;
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		if (a[x][y] == 'v') v++;
		else if (a[x][y] == 'k') k++;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (!check[nx][ny] && a[nx][ny] != '#') {
					check[nx][ny] = true;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	if (k > v) sheep += k;
	else wolf += v;
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
			if (!check[i][j] && (a[i][j] == 'v' || a[i][j] == 'k')) {
				bfs(i, j);
			}
		}
	}
	cout << sheep << ' ' << wolf << '\n';

	return 0;
}