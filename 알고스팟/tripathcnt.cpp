#include <iostream>
#include <cstring>
using namespace std;
int a[100][100];
int cache[100][100];
int countCache[100][100];
int n;

int path(int x, int y) {
	if (x == n - 1) {
		return a[x][y];
	}
	int& ret = cache[x][y];
	if (ret != -1) return ret;
	return ret = a[x][y] + max(path(x + 1, y), path(x + 1, y + 1));
}
int count(int x, int y) {
	if (x == n - 1) {
		return 1;
	}
	int& ret = countCache[x][y];
	if (ret != -1) return ret;
	ret = 0;
	if (path(x + 1, y) >= path(x + 1, y + 1)) ret += count(x + 1, y);
	if (path(x + 1, y) <= path(x + 1, y + 1)) ret += count(x + 1, y + 1);
	return ret;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		memset(cache, -1, sizeof(cache));
		memset(countCache, -1, sizeof(countCache));
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i + 1; j++) {
				cin >> a[i][j];
			}
		}
		cout << count(0, 0) << '\n';
	}

	return 0;
}