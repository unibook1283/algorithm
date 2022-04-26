#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
char a[12][6];
bool check[12][6];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
vector<pair<int, int>> bfs(int x, int y) {
	vector<pair<int, int>> v;
	check[x][y] = true;
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		v.push_back(make_pair(x, y));
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < 12 && ny >= 0 && ny < 6) {
				if (a[nx][ny] == a[x][y] && check[nx][ny] == false) {
					check[nx][ny] = true;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	return v;
}
void boom_puyo(vector<pair<int, int>>& boom) {
	for (int i = 0; i < boom.size(); i++) {
		int x = boom[i].first;
		int y = boom[i].second;
		a[x][y] = '.';
	}
}
void gravity() {
	for (int i = 11; i > 0; i--) {
		for (int j = 0; j < 6; j++) {
			int h = 0;
			if (a[i][j] == '.') {
				while (1) {
					h++;
					if (i - h < 0) break;
					if (a[i - h][j] != '.') {
						a[i][j] = a[i - h][j];
						a[i - h][j] = '.';
						break;
					}
				}
			}
			
		}
	}
}
int main() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> a[i][j];
		}
	}

	int ans = 0;
	while (1) {
		memset(check, false, sizeof(check));
		vector<pair<int, int>> boom;
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (a[i][j] != '.' && check[i][j] == false) {
					vector<pair<int,int>> temp = bfs(i, j);
					if (temp.size() >= 4) {
						while (!temp.empty()) {
							boom.push_back(temp.back());
							temp.pop_back();
						}
					}
				}
			}
		}
		if (boom.empty()) break;
		boom_puyo(boom);
		gravity();

		ans++;
	}
	cout << ans << '\n';

	return 0;
}