#include <iostream>
using namespace std;
long long a[1000001];
int n;
long long m;
bool enough(long long h) {
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		long long dif = a[i] - h;
		if (dif > 0) sum += dif;
	}
	return sum >= m;
}
int main() {
	cin >> n >> m;
	long long left = 0;
	long long right = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (right < a[i]) right = a[i];
	}
	long long ans = 0;
	while (left <= right) {
		long long mid = (left + right) / 2;
		if (enough(mid)) {
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