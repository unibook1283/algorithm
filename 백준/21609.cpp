#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int a[21][21];
int d[21][21];
int n, m;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int ans = 0;
vector<pair<int, int>> blocks;
int bfs(int x, int y) {
	int rainbow = 0;
	int color = a[x][y];
	d[x][y] = color;
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		blocks.push_back(make_pair(x, y));
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
				if (d[nx][ny] != color) {
					if (a[nx][ny] == 0 || a[nx][ny] == color) {
						if (a[nx][ny] == 0) rainbow++;
						d[nx][ny] = color;
						q.push(make_pair(nx, ny));
					}
				}
			}
		}
	}
	return rainbow;
}
void remove_block(vector<pair<int, int>>& biggest_block) {
	int size = biggest_block.size();
	for (int i = 0; i < size; i++) {
		int x = biggest_block[i].first;
		int y = biggest_block[i].second;
		a[x][y] = -2;
	}
	ans += size * size;
}
void gravity() {
	for (int i = n - 1; i >= 0; i--) {
		for (int j = n - 1; j >= 0; j--) {
			if (a[i][j] == -2) {
				int x = i, y = j;
				while (1) {
					x--;
					if (x < 0) break;
					if (a[x][y] == -1) break;
					if (a[x][y] != -2) {
						a[i][j] = a[x][y];
						a[x][y] = -2;
						break;
					}
				}
			}
		}
	}
}
void rotate() {
	vector<vector<int>> temp(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			temp[i][j] = a[j][n - i - 1];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = temp[i][j];
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	while (1) {
		memset(d, -1, sizeof(d));

		vector<pair<int, int>> biggest_block;
		int biggests_rainbow = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (d[i][j] == -1 && a[i][j] != 0 && a[i][j] != -1 && a[i][j] != -2) {
					blocks.clear();
					int rainbow = bfs(i, j);
					if (blocks.size() > biggest_block.size()) {
						biggest_block.assign(blocks.begin(), blocks.end());
						biggests_rainbow = rainbow;
					}
					else if (blocks.size() == biggest_block.size()) {
						if (rainbow >= biggests_rainbow) {
							biggest_block.assign(blocks.begin(), blocks.end());
							biggests_rainbow = rainbow;
						}
					}
				}
			}
		}
		if (biggest_block.size() < 2) break;
		remove_block(biggest_block);
		gravity();
		rotate();
		gravity();
	}
	cout << ans << '\n';

	return 0;
}