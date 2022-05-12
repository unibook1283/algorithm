#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
const int MAX = 8;
char a[MAX][MAX];
bool check[MAX][MAX][9];
int dx[] = { -1,-1,-1,0,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,0,1,-1,0,1 };
int ans = 0;
void bfs(int x, int y, int t) {
	check[x][y][t] = true;
	queue<tuple<int, int, int>> q;
	q.push(make_tuple(x, y, t));
	while (!q.empty()) {
		tie(x, y, t) = q.front();
		q.pop();
		if (x == 0 && y == 7) ans = 1;
		for (int i = 0; i < 9; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nt = min(t + 1, MAX);
			if (nx >= 0 && nx < MAX && ny >= 0 && ny < MAX) {
				if (nx - t >= 0 && a[nx - t][ny] == '#') continue;
				if (nx - t - 1 >= 0 && a[nx - t - 1][ny] == '#')	continue;
				if (check[nx][ny][nt] == false) {
					check[nx][ny][nt] = true;
					q.push(make_tuple(nx, ny, nt));
				}
			}
		}
	}
}
int main() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			cin >> a[i][j];
		}
	}
	bfs(7, 0, 0);

	cout << ans << '\n';

	return 0;
}