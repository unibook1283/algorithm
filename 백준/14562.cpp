#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int d[1000][1000];
int bfs(int x, int y) {
	d[x][y] = 0;
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		if (x == y) return d[x][y];
		int nx = 2 * x;
		int ny = y + 3;
		if (nx < 1000 && ny < 1000 && d[nx][ny] == -1) {
			d[nx][ny] = d[x][y] + 1;
			q.push(make_pair(nx, ny));
		}
		nx = x + 1;
		ny = y;
		if (nx < 1000 && ny < 1000 && d[nx][ny] == -1) {
			d[nx][ny] = d[x][y] + 1;
			q.push(make_pair(nx, ny));
		}
	}
	return -1;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		memset(d, -1, sizeof(d));
		cout << bfs(a, b) << '\n';
	}

	return 0;
}