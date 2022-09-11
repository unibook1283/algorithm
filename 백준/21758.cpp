#include <iostream>
using namespace std;
int a[100002];
int sum[100002];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}

	int ans = 0;
	// 国 - 国 - 曹烹
	for (int i = 2; i < n; i++) {	// i : 啊款单 国狼 困摹
		ans = max(ans, (sum[n] - sum[1] - a[i]) + (sum[n] - sum[i]));
	}
	
	// 国 - 曹烹 - 国
	for (int i = 2; i < n; i++) {	// i : 曹烹狼 困摹
		ans = max(ans, (sum[i] - sum[1]) + (sum[n - 1] - sum[i - 1]));
	}

	// 曹烹 - 国 -国
	for (int i = 2; i < n; i++) {	// i : 啊款单 国狼 困摹
		ans = max(ans, (sum[i - 1] - sum[0]) + (sum[n - 1] - sum[0] - a[i]));
	}

	cout << ans << '\n';

	return 0;
}