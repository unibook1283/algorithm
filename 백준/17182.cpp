#include <iostream>
using namespace std;
int a[11][11];
bool check[11];
int n, k;
int ans = 987654321;
void dfs(int cur, int cnt, int cost) {
	if (cost > ans) return;
	if (cnt == n) {
		ans = min(ans, cost);
		return;
	}
	for (int i = 0; i < n; i++) {
		if (check[i]) continue;
		check[i] = true;
		dfs(i, cnt + 1, cost + a[cur][i]);
		check[i] = false;
	}
}
int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
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
	check[k] = true;
	dfs(k, 1, 0);

	cout << ans << '\n';

	return 0;
}