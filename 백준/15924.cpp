#include <iostream>
#include <cstring>
using namespace std;
char a[3001][3001];
int cache[3001][3001];
int n, m;
int dx[] = { 1,0 };
int dy[] = { 0,1 };
const int MOD = 1000000009;
int go(int x, int y) {
	if (x == n - 1 && y == m - 1) return 1;
	int& ret = cache[x][y];
	if (ret != -1) return ret;
	ret = 0;
	if (a[x][y] != 'E' && x + 1 < n)
		ret = (ret + go(x + 1, y)) % MOD;
	if (a[x][y] != 'S' && y + 1 < m)
		ret = (ret + go(x, y + 1)) % MOD;
	return ret;
}
int main() {
	memset(cache, -1, sizeof(cache));
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ans = (ans + go(i, j)) % MOD;
		}
	}
	cout << ans << '\n';

	return 0;
}