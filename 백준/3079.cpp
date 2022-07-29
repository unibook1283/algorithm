#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	vector<long long> t(n);
	long long left = 0, right = 0;
	for (int i = 0; i < n; i++) {
		cin >> t[i];
		right = max(right, t[i]);
	}
	right *= m;

	long long ans = 0;
	while (left <= right) {
		long long mid = (left + right) / 2;
		long long cnt = 0;
		for (int i = 0; i < n; i++) {
			cnt += mid / t[i];
		}
		if (cnt >= m) {
			ans = mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	cout << ans << '\n';

	return 0;
}