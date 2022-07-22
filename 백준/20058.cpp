#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
int a[65][65];
int d[65][65];
int n, m;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
void rotate_map(int x, int y, int length) {
	vector<vector<int>> copy_a(length, vector<int>(length));
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			copy_a[i][j] = a[x + i][y + j];
		}
	}
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			a[x + i][y + j] = copy_a[length - j -1][i];
		}
	}
}
int adj_ice(int x, int y) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
			if (a[nx][ny] != 0) cnt++;
		}
	}
	return cnt;
}
int bfs(int x, int y) {
	int cnt = 0;
	d[x][y] = 0;
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		cnt++;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
				if (d[nx][ny] == -1 && a[nx][ny] != 0) {
					d[nx][ny] = d[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	return cnt;
}
int main() {
	cin >> n >> m;
	n = (1 << n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	while (m--) {
		int l;
		cin >> l;
		l = (1 << l);
		for (int i = 0; i < n; i += l) {
			for (int j = 0; j < n; j += l) {
				rotate_map(i, j, l);
			}
		}
		vector<pair<int, int>> melt;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] == 0) continue;
				if (adj_ice(i, j) < 3) {
					melt.push_back(make_pair(i, j));
				}
			}
		}
		for (int i = 0; i < melt.size(); i++) {
			int x = melt[i].first;
			int y = melt[i].second;
			a[x][y]--;
		}
	}

	memset(d, -1, sizeof(d));
	int sum = 0, maxi = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sum += a[i][j];
			if (a[i][j] != 0 && d[i][j] == -1) {
				maxi = max(maxi, bfs(i, j));
			}
		}
	}
	cout << sum << '\n' << maxi << '\n';
	
	return 0;
}