#include <iostream>
#include <cstring>
using namespace std;
char a[51][51];
bool check[51][51];
int cache[51][51];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int n, m;
int go(int x, int y) {
	if (a[x][y] == 'H' || a[x][y] == '0') return 0;
	int& ret = cache[x][y];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + (a[x][y] - '0') * dx[i];
		int ny = y + (a[x][y] - '0') * dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
			if (check[nx][ny]) return -1;
			check[nx][ny] = true;
			int res = go(nx, ny);
			if (res == -1) return res;
			ret = max(ret, res);
			check[nx][ny] = false;
		}
	}
	ret++;
	return ret;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	memset(cache, -1, sizeof(cache));
	check[0][0] = true;
	cout << go(0, 0) << '\n';

	return 0;
}