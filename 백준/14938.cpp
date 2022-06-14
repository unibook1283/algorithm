#include <iostream>
using namespace std;
#define INF 987654321
int item[101];
int d[101][101];
int main() {
	int n, m, r;
	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++) {
		cin >> item[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) d[i][j] = INF;
		}
	}

	for (int i = 0; i < r; i++) {
		int a, b, l;
		cin >> a >> b >> l;
		d[a][b] = l;
		d[b][a] = l;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (d[j][k] > d[j][i] + d[i][k]) {
					d[j][k] = d[j][i] + d[i][k];
				}
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = 1; j <= n; j++) {
			if (d[i][j] <= m) {
				sum += item[j];
			}
		}
		ans = max(ans, sum);
	}
	cout << ans << '\n';

	return 0;
}