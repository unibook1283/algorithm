#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
char a[5][5];
bool check[5][5];
bool bCheck[5][5];
vector<pair<int, int>> stars;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int minDist = 987654321;
int bfs(int x, int y) {
	memset(bCheck, false, sizeof(bCheck));
	int count = 0;
	bCheck[x][y] = true;
	queue<pair<int, int>> q;
	q.push({ x,y });
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		count++;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5) {
				if (!bCheck[nx][ny] && check[nx][ny]) {
					bCheck[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
		}
	}
	return count;
}
bool allConnected() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (check[i][j]) {
				int count = bfs(i, j);
				if (count == stars.size()) {
					return true;
				}
				else {
					return false;
				}
			}
		}
	}
	return false;
}
void go(int starIndex, int dist) {
	if (dist >= minDist) return;
	if (starIndex == stars.size()) {
		if (allConnected()) {
			minDist = min(minDist, dist);
		}
		return;
	}
	int sx = stars[starIndex].first;
	int sy = stars[starIndex].second;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (!check[i][j]) {
				check[i][j] = true;
				go(starIndex + 1, dist + abs(i - sx) + abs(j - sy));
				check[i][j] = false;
			}
		}
	}
}
int main() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> a[i][j];
			if (a[i][j] == '*') {
				stars.push_back({ i,j });
			}
		}
	}
	
	go(0, 0);
	cout << minDist << '\n';

	return 0;
}