#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
int a[100][100];
bool check[100][100];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
void melt(vector<pair<int, int>>& v) {
	for (int i = 0; i < v.size(); i++) {
		int x = v[i].first;
		int y = v[i].second;
		a[x][y] = 0;
	}
}
void bfs(int x, int y) {
	vector<pair<int, int>> v;
	check[x][y] = true;
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
				if (a[nx][ny] == 0 && check[nx][ny] == false) {
					check[nx][ny] = true;
					q.push(make_pair(nx, ny));
				}
				if (a[nx][ny] == 1 && check[nx][ny] == false) {
					check[nx][ny] = true;
					v.push_back(make_pair(nx, ny));
				}
			}
		}
	}
	melt(v);
}
int count() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 1) cnt++;
		}
	}
	return cnt;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	int cnt = count();
	int hour = 0;
	while (cnt > 0) {
		hour++;
		memset(check, false, sizeof(check));
		bfs(0, 0);
		int temp = count();
		if (temp == 0) break;
		cnt = temp;
	}
	cout << hour << '\n' << cnt << '\n';

	return 0;
}