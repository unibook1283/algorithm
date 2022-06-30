#include <iostream>
using namespace std;
long long a[10001];
int k, n;
bool possible(long long length) {
	int cnt = 0;
	for (int i = 0; i < k; i++) {
		cnt += a[i] / length;
	}
	return n <= cnt;
}
int main() {
	cin >> k >> n;
	long long left = 1, right = 0;
	for (int i = 0; i < k; i++) {
		cin >> a[i];
		right = max(right, a[i]);
	}

	long long ans = 0;
	while (left <= right) {
		long long mid = (left + right) / 2;
		if (possible(mid)) {
			ans = max(ans, mid);
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	cout << ans << '\n';


	return 0;
}