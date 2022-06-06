#include <iostream>
#include <algorithm>
using namespace std;
int a[1000][1000];
int d[1000][1000];
int main() {
	int m, n;
	int ans = 0;
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (a[i][j] == 0) {
				d[i][j] = 1;
				ans = 1;
			}
		}
	}

	int mini;
	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++) {
			if (d[i][j]) {
				mini = min({ d[i - 1][j], d[i - 1][j - 1], d[i][j - 1] });
				d[i][j] = mini + 1;
				ans = max(ans, d[i][j]);
			}
		}
	}
	cout << ans << '\n';

	return 0;
}