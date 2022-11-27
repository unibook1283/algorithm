#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
char a[101][101];
int d[101][101][3];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int n, m;
const int INF = 987654321;
void bfs(int x, int y, int index) {
	d[x][y][index] = 0;
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
				if (d[nx][ny][index] == -1 && a[nx][ny] == '0') {
					d[nx][ny][index] = d[x][y][index] + 1;
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
		}
	}
	memset(d, -1, sizeof(d));
	for (int i = 0; i < 3; i++) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		bfs(x, y, i);
	}

	int mini = INF;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int maxi = -1;
			bool possible = true;
			for (int k = 0; k < 3; k++) {
				if (d[i][j][k] == -1) {
					possible = false;
					break;
				}
				maxi = max(maxi, d[i][j][k]);
			}
			if (!possible) continue;
			if (mini == maxi) {
				cnt++;
			}
			else if (mini > maxi) {
				mini = maxi;
				cnt = 1;
			}
		}
	}
	if (mini == INF) cout << "-1\n";
	else {
		cout << mini << '\n';
		cout << cnt << '\n';
	}

	return 0;
}