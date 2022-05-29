#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int n, m;
int a[50][50];
int d[50][50];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
void bfs(vector<int>& v, vector<pair<int, int>>& virus) {
	queue <pair<int, int>> q;
	int vsize = v.size();
	for (int i = 0; i < vsize; i++) {
		if (v[i] == 1) {
			int x = virus[i].first;
			int y = virus[i].second;
			q.push(make_pair(x, y));
			d[x][y] = 0;
		}
	}
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
				if (d[nx][ny] == -1 && a[nx][ny] != 1) {
					d[nx][ny] = d[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}
int min_time() {
	int mt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] != 0) continue;
			if (d[i][j] == -1) return -1;
			mt = max(mt, d[i][j]);
		}
	}
	return mt;
}
int main() {
	cin >> n >> m;
	vector<pair<int, int>> virus;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (a[i][j] == 2) {
				virus.push_back(make_pair(i, j));
			}
		}
	}
	int vsize = virus.size();
	vector<int> v;
	for (int i = 0; i < vsize - m; i++) {
		v.push_back(0);
	}
	for (int i = 0; i < m; i++) {
		v.push_back(1);
	}
	
	int ans = -1;
	do {
		memset(d, -1, sizeof(d));
		bfs(v, virus);
		
		int time = min_time();
		if (ans == -1) ans = time;
		if (time != -1 && ans > time) {
			ans = time;
		}

	} while (next_permutation(v.begin(), v.end()));

	cout << ans << '\n';

	return 0;
}