#include <iostream>
#include <queue>
using namespace std;
int a[65][65];
bool check[65][65];
int dx[] = { 1,0 };
int dy[] = { 0,1 };
int n;
string bfs() {
	check[0][0] = 0;
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (x == n - 1 && y == n - 1) return "HaruHaru";
		for (int i = 0; i < 2; i++) {
			int nx = x + a[x][y] * dx[i];
			int ny = y + a[x][y] * dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
				if (check[nx][ny] == false) {
					check[nx][ny] = true;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	return "Hing";
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	cout << bfs() << '\n';

	return 0;
}