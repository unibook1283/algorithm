#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int a[21], p[21];
bool check[21];
int n, k;
int ans = 0;
void dfs(int x, int prev_sum, int total_sum, int resident) {
	ans = max(ans, resident);
	check[x] = true;
	for (int i = 0; i < n; i++) {
		if (!check[i]) {
			if (total_sum + prev_sum + a[i] <= k)
				dfs(i, prev_sum + a[i], total_sum + prev_sum + a[i], resident + p[i]);
		}
	}
	check[x] = false;
}
int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> p[i];

	for (int i = 0; i < n; i++) {
		dfs(n, 0, 0, 0);
	}
	cout << ans << '\n';

	return 0;
}