#include <iostream>
#include <vector>
using namespace std;
int a[101][101];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	int ans = n * m * 2;

	for (int i = 0; i < n; i++) {
		int prev[2] = { 0, };
		for (int j = 0; j < m; j++) {
			int dif[2];
			dif[0] = a[i][j] - prev[0];
			dif[1] = a[i][m - j - 1] - prev[1];

			for (int k = 0; k < 2; k++) {
				if (dif[k] > 0) {
					ans += dif[k];
				}
			}
			prev[0] = a[i][j];
			prev[1] = a[i][m - j - 1];
		}
	}

	for (int i = 0; i < m; i++) {
		int prev[2] = { 0, };
		for (int j = 0; j < n; j++) {
			int dif[2];
			dif[0] = a[j][i] - prev[0];
			dif[1] = a[n - j - 1][i] - prev[1];

			for (int k = 0; k < 2; k++) {
				if (dif[k] > 0) {
					ans += dif[k];
				}
			}
			prev[0] = a[j][i];
			prev[1] = a[n - j - 1][i];
		}
	}

	cout << ans << '\n';

	return 0;
}