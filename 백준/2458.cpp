#include <iostream>
using namespace std;
int a[501][501];
int cnt[501];
const int INF = 987654321;
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = i == j ? 0 : INF;
		}
	}
	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;
		from--; to--;
		a[from][to] = 1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (a[j][k] > a[j][i] + a[i][k]) {
					a[j][k] = a[j][i] + a[i][k];
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			else if (a[i][j] < INF) {
				cnt[i]++; cnt[j]++;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (cnt[i] == n - 1) ans++;
	}
	cout << ans << '\n';

	return 0;
}