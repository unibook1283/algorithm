#include <iostream>
#include <cstring>
using namespace std;
int dx[] = { 0,1 };
int dy[] = { 1,0 };
int a[101][101];
int n;
int cache[101][101];
bool go(int x, int y) {
	int num = a[x][y];
	if (x >= n || y >= n) return false;
	if (num == 0) return true;
	int& ret = cache[x][y];
	if (ret != -1) return ret;
	for (int i = 0; i < 2; i++) {
		int nx = x + num * dx[i];
		int ny = y + num * dy[i];
		if (ret = go(nx, ny)) return true;
	}
	return false;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		memset(cache, -1, sizeof(cache));
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
			}
		}
		if (go(0, 0)) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}