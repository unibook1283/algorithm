#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int a[50][50];
bool check[50][50];
int n, m;
int dx[] = { 0,-1,0,1 };
int dy[] = { -1,0,1,0 };
int bfs(int x, int y) {
	check[x][y] = true;
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	int cnt = 0;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		cnt++;
		for (int i = 0; i < 4; i++) {
			if (!(a[x][y] & (1 << i))) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
					if (check[nx][ny] == false) {
						check[nx][ny] = true;
						q.push(make_pair(nx, ny));
					}
				}
			}
		}
	}
	return cnt;
}
int main() {
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	int room_cnt = 0;
	int max_room = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (check[i][j] == false) {
				max_room = max(max_room, bfs(i, j));
				room_cnt++;
			}
		}
	}

	int max_room_after_remove = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < 4; k++) {
				if (a[i][j] & (1 << k)) {
					memset(check, false, sizeof(check));
					a[i][j] -= (1 << k);
					max_room_after_remove = max(max_room_after_remove, bfs(i, j));
					a[i][j] += (1 << k);
				}
			}
		}
	}
	cout << room_cnt << '\n' << max_room << '\n' << max_room_after_remove << '\n';

	return 0;
}