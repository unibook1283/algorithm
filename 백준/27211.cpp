#include <iostream>
#include <queue>
using namespace std;
int a[1001][1001];
bool check[1001][1001];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int n, m;
void bfs(int x, int y) {
	check[x][y] = true;
	queue<pair<int, int>> q;
	q.push({ x,y });
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = (x + dx[i] + n) % n;
			int ny = (y + dy[i] + m) % m;
			if (a[nx][ny] == 0 && !check[nx][ny]) {
				check[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];

	int answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 0 && !check[i][j]) {
				bfs(i, j);
				answer++;
			}
		}
	}
	cout << answer << '\n';

	return 0;
}