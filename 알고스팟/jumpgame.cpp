#include <iostream>
#include <cstring>
using namespace std;
int a[101][101];
bool check[101][101];
int n;
bool dfs(int x, int y) {
	if (x == n - 1 && y == n - 1) return true;
	check[x][y] = true;
	int jumpSize = a[x][y];
	if (x + jumpSize < n) {
		if (!check[x + jumpSize][y]) {
			if (dfs(x + jumpSize, y)) return true;
		}
	}
	if (y + jumpSize < n) {
		if (!check[x][y + jumpSize]) {
			if (dfs(x, y + jumpSize)) return true;
		}
	}
	return false;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		memset(check, false, sizeof(check));
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
			}
		}
		if (dfs(0, 0)) {
			cout << "YES\n";
			continue;
		}
		cout << "NO\n";
	}

	return 0;
}