#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int a[20][20];
int d[20][20];
int n;
int sx, sy;
int shark_size = 2;
int shark_eaten = 0;
int dx[] = { -1,0,0,1 };
int dy[] = { 0,-1,1,0 };
int bfs(int x, int y, vector<pair<int, int>>& minfish) {
	int mindist = -1;
	d[x][y] = 0;
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		if (d[x][y] == mindist) return mindist;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
				if (d[nx][ny] == -1) {
					if (a[nx][ny] == 0 || a[nx][ny] == shark_size) {
						d[nx][ny] = d[x][y] + 1;
						q.push(make_pair(nx, ny));
					}
					else if (a[nx][ny] < shark_size) {
						minfish.push_back(make_pair(nx, ny));
						mindist = d[x][y] + 1;
					}
				}
			}
		}
	}
	return mindist;
}
void eat_fish(vector<pair<int, int>>& minfish) {
	sort(minfish.begin(), minfish.end());

	sx = minfish.front().first;
	sy = minfish.front().second;
	a[sx][sy] = 0;
	shark_eaten++;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (a[i][j] == 9) {
				sx = i;
				sy = j;
				a[i][j] = 0;
			}
		}
	}
	int ans = 0;
	while (1) {
		memset(d, -1, sizeof(d));

		vector<pair<int, int>> minfish;
		int mindist = bfs(sx, sy, minfish);
		if (minfish.empty()) break;
		ans += mindist;

		eat_fish(minfish);

		if (shark_eaten == shark_size) {
			shark_size++;
			shark_eaten = 0;
		}
	}
	cout << ans << '\n';

	return 0;
}