#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
int a[1000][1000];
int check[1000][1000];
int d[500000];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int n, m;
void bfs(int x, int y, int index) {
	int cnt = 0;
	check[x][y] = true;
	queue<pair<int, int>> q, p;
	q.push(make_pair(x, y));
	p.push(make_pair(x, y));
	while (!q.empty()) {
		cnt++;
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (a[nx][ny] == 1 && check[nx][ny] == false) {
					check[nx][ny] = true;
					q.push(make_pair(nx, ny));
					p.push(make_pair(nx, ny));
				}
			}
		}
	}
	while (!p.empty()) {
		x = p.front().first;
		y = p.front().second;
		p.pop();
		a[x][y] = index;
	}
	d[index] = cnt;
}
bool is_redundancy(vector<int>& v, int index) {
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == index) return true;
	}
	return false;
}
int main() {
	cin >> n >> m;
	vector<pair<int, int>> zero;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 0) zero.push_back(make_pair(i, j));
		}
	}
	int index = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 1 && check[i][j] == false) {
				bfs(i, j, index++);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < zero.size(); i++) {
		int size = 1;
		int x = zero[i].first;
		int y = zero[i].second;
		vector<int> v;
		for (int j = 0; j < 4; j++) {
			int nx = x + dx[j];
			int ny = y + dy[j];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (a[nx][ny] != 0) {
					int idx = a[nx][ny];
					if (is_redundancy(v, idx)) continue;
					v.push_back(idx);
					size += d[idx];
				}
			}
		}
		ans = max(ans, size);
	}
	cout << ans << '\n';
	return 0;
}