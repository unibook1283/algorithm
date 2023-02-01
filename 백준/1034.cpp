#include <iostream>
using namespace std;
string a[51];
int main() {
	int n, m, k;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cin >> k;

	int ans = 0;
	for (int i = 0; i < n; i++) {
		int zero_cnt = 0;
		for (int j = 0; j < m; j++) {
			if (a[i][j] == '0') zero_cnt++;
		}
		if (zero_cnt > k || zero_cnt % 2 != k % 2) continue;
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (a[i] == a[j]) cnt++;
		}
		ans = max(ans, cnt);
	}
	cout << ans << '\n';

	return 0;
}