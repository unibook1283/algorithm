#include <iostream>
#include <vector>
using namespace std;
int a[16];
int main() {
	int n, l, r, x;
	cin >> n >> l >> r >> x;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int ans = 0;
	for (int i = 0; i < (1 << n); i++) {
		int maxi = 0, mini = 987654321, sum = 0;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				sum += a[j];
				maxi = max(maxi, a[j]);
				mini = min(mini, a[j]);
			}
		}
		if (sum >= l && sum <= r && maxi - mini >= x) {
			ans++;
		}
	}
	cout << ans << '\n';

	return 0;
}