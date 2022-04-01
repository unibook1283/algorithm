#include <iostream>
#include <queue>
using namespace std;
char a[50][50];
int dist[50][50];
pair<int, int> d;
queue<pair<int, int>> q;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int r, c;
int bfs(int sx, int sy) {
	q.push(make_pair(sx, sy));
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
				if (dist[x][y] == -1) {
					if (a[nx][ny] == 'D' || a[nx][ny] == 'X' || (nx == sx && ny == sy)) continue;
					if (dist[nx][ny] == 0) {
						dist[nx][ny] = -1;
						q.push(make_pair(nx, ny));
					}
				}
				else {
					if (a[nx][ny] == 'D') return dist[x][y] + 1;
					if (a[nx][ny] == '.' && dist[nx][ny] == 0) {
						dist[nx][ny] = dist[x][y] + 1;
						q.push(make_pair(nx, ny));
					}
				}
			}
		}
		
		
	}
	return -1;
}
int main() {
	cin >> r >> c;
	int x, y;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'D') d = make_pair(i, j);
			else if (a[i][j] == '*') {
				q.push(make_pair(i, j));
				dist[i][j] = -1;
			}
			else if (a[i][j] == 'S') {
				x = i;
				y = j;
			}
		}
	}
	int ans = bfs(x, y);
	if (ans == -1) cout << "KAKTUS";
	else cout << ans;


	return 0;
}
/*
-이건 하나의 queue에 물을 먼저 넣고 S를 뒤에 넣어서 번갈아가면서 푼것.
 물*과 S가 붙어있는 경우를 따로 처리해줘야됨.
-3055(2)는 물이 잠기는 시간을 bfs로 미리 구하고 S를 다시 bfs 해서 푼것.(백준 pdf에 있는 방법)
*/