#include <iostream>
#include <cstring>
using namespace std;
int a[100][100];
int cache[100][100];
int n;
int go(int x, int y) {
	if (x == n - 1) {
		return a[x][y];
	}
	int& ret = cache[x][y];
	if (ret != -1) return ret;
	return ret = a[x][y] + max(go(x + 1, y), go(x + 1, y + 1));
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		memset(cache, -1, sizeof(cache));
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i + 1; j++) {
				cin >> a[i][j];
			}
		}
		cout << go(0, 0) << '\n';
	}

	return 0;
}