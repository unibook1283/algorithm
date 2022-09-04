#include <iostream>
using namespace std;
int a[1000001];
int main() {
	int m, n;
	cin >> m >> n;
	int left = 1, right = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		right = max(right, a[i]);
	}

	int ans = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			cnt += a[i] / mid;
		}
		if (cnt < m) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
			ans = mid;
		}
	}
	cout << ans << '\n';

	return 0;
}