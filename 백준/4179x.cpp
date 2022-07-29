#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
char a[1001][1001];
int f[1001][1001];
int j[1001][1001];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int n, m;
int main() {
	memset(f, -1, sizeof(f));
	memset(j, -1, sizeof(j));
	cin >> n >> m;
	queue<pair<int, int>> jihun, fire;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			cin >> a[i][k];
			if (a[i][k] == 'J') {
				j[i][k] = 0;
				jihun.push(make_pair(i, k));
			}
			else if (a[i][k] == 'F') {
				f[i][k] = 0;
				fire.push(make_pair(i, k));
			}
		}
	}
	
	while (!fire.empty()) {
		int x = fire.front().first;
		int y = fire.front().second;
		fire.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (a[nx][ny] != '#' && f[nx][ny] == -1) {
					f[nx][ny] = f[x][y] + 1;
					fire.push(make_pair(nx, ny));
				}
			}
		}
	}

	while (!jihun.empty()) {
		int x = jihun.front().first;
		int y = jihun.front().second;
		jihun.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (a[nx][ny] == '.' && j[nx][ny] == -1 && j[x][y] + 1 < f[nx][ny]) {
					j[nx][ny] = j[x][y] + 1;
					jihun.push(make_pair(nx, ny));
				}
			}
			else {
				cout << j[x][y] + 1 << '\n';
				return 0;
			}
		}
	}
	cout << "IMPOSSIBLE\n";
	
	return 0;
}