#include <iostream>
#include <cstring>
using namespace std;
int n, m, c;
int a[1001];
int b[1001];
long long w[20][20];
long long cache[1001][1001];
long long go(int x, int y) {
	if (x == n || y == m) return 0;
	long long& ret = cache[x][y];
	if (ret != -1) return ret;
	ret = 0;
	ret = max(ret, go(x + 1, y));
	ret = max(ret, go(x, y + 1));
	ret = max(ret, w[a[x]][b[y]] + go(x + 1, y + 1));
	return ret;
}
int main() {
	cin >> n >> m >> c;
	for (int i = 1; i <= c; i++)
		for (int j = 1; j <= c; j++)
			cin >> w[i][j];

	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++)
		cin >> b[i];

	memset(cache, -1, sizeof(cache));
	cout << go(0, 0) << '\n';

	return 0;
}