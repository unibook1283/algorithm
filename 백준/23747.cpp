#include <iostream>
#include <queue>
using namespace std;
char a[1001][1001];
char check[1001][1001];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int n, m;
void bfs(int x, int y) {
	check[x][y] = '.';
	char color = a[x][y];
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (check[nx][ny] == '#' && a[nx][ny] == color) {
					check[nx][ny] = '.';
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			check[i][j] = '#';
		}
	}
	int x, y;
	cin >> x >> y;
	x--; y--;
	string s;
	cin >> s;

	for (char ch : s) {
		if (ch == 'U') {
			x--;
		}
		else if (ch == 'D') {
			x++;
		}
		else if (ch == 'L') {
			y--;
		}
		else if (ch == 'R') {
			y++;
		}
		else if (ch == 'W') {
			bfs(x, y);
		}
	}

	check[x][y] = '.';
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
			check[nx][ny] = '.';
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << check[i][j];
		}
		cout << '\n';
	}
	cout << '\n';

	return 0;
}