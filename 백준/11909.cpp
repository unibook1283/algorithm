#include <iostream>
#include <cstring>
using namespace std;
const int INF = 987654321;
int a[2223][2223];
int cache[2223][2223];
int n;
int dx[] = { 0,1 };
int dy[] = { 1,0 };
int go(int x, int y) {
	if (x == n - 1 && y == n - 1) {
		return 0;
	}
	int& ret = cache[x][y];
	if (ret != -1) return ret;
	ret = INF;
	for (int i = 0; i < 2; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
			int cost = max(0, a[nx][ny] - a[x][y] + 1);
			ret = min(ret, go(nx, ny) + cost);
		}
	}
	return ret;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	memset(cache, -1, sizeof(cache));
	cout << go(0, 0) << '\n';

	return 0;
}