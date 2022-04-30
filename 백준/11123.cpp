#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
char a[100][100];
bool check[100][100];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int h, w;
void bfs(int x, int y) {
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
			if (nx >= 0 && nx < h && ny >= 0 && ny < w) {
				if (a[nx][ny] == '#' && check[nx][ny] == false) {
					check[nx][ny] = true;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}
int main() {
	int t;
	cin >> t;
	while(t--) {
		memset(check, false, sizeof(check));
		cin >> h >> w;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> a[i][j];
			}
		}
		int components = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (a[i][j] == '#' && check[i][j] == false) {
					bfs(i, j);
					components++;
				}
			}
		}
		cout << components << '\n';
	}
	
	return 0;
}