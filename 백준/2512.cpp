#include <iostream>
using namespace std;
long long a[10001];
long long n, m;
bool check(long long mid) {
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		sum += min(mid, a[i]);
	}
	return sum <= m;
}
int main() {
	cin >> n;
	long long left = 0, right = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		right = max(right, a[i]);
	}
	cin >> m;

	long long ans = 0;
	while (left <= right) {
		long long mid = (left + right) / 2;
		if (check(mid)) {
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