#include <iostream>
using namespace std;
int a[301][301];
int d[301][301];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			d[i][j] = max(d[i - 1][j], d[i][j - 1]) + a[i][j];
		}
	}
	cout << d[n][m] << '\n';

	return 0;
}