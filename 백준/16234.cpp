#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int a[51][51];
bool check[51][51];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int n, l, r;
vector<pair<int, int>> bfs(int x, int y) {
	vector<pair<int, int>> ret;
	ret.push_back(make_pair(x, y));
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
			if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
				if (!check[nx][ny]) {
					int dif = abs(a[x][y] - a[nx][ny]);
					if (l <= dif && dif <= r) {
						check[nx][ny] = true;
						q.push(make_pair(nx, ny));
						ret.push_back(make_pair(nx, ny));
					}
				}
			}
		}
	}
	return ret;
}
void population_move(vector<pair<int, int>> adj_nations) {
	int sum = 0;
	for (int i = 0; i < adj_nations.size(); i++)
		sum += a[adj_nations[i].first][adj_nations[i].second];
	int mean = sum / adj_nations.size();
	for (int i = 0; i < adj_nations.size(); i++)
		a[adj_nations[i].first][adj_nations[i].second] = mean;
}
int main() {
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];

	int ans = 0;
	while (1) {
		memset(check, false, sizeof(check));
		bool finish = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!check[i][j]) {
					vector<pair<int,int>> adj_nations = bfs(i, j);
					if (adj_nations.size() != 1) {
						population_move(adj_nations);
						finish = false;
					}
				}
			}
		}
		if (finish) break;
		ans++;
	}
	cout << ans << '\n';

	return 0;
}