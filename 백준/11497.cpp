#include <iostream>
#include <algorithm>
using namespace std;
int a[100001];
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a, a + n);

		int ans = 0;
		ans = max(ans, abs(a[n - 1] - a[n - 2]));
		ans = max(ans, abs(a[1] - a[0]));

		for (int i = 0; i < n - 2; i++) {
			ans = max(ans, abs(a[i] - a[i + 2]));
		}
		
		cout << ans << '\n';
	}

	return 0;
}