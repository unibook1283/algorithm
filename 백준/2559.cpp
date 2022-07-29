#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	vector<int> sum(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum[i + 1] = sum[i] + a[i];
	}
	int ans = -10000000;
	for (int i = 0; i < n - k + 1; i++) {
		ans = max(ans, sum[i + k] - sum[i]);
	}
	cout << ans << '\n';

	return 0;
}