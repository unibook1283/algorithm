#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<int> a(n), b(m);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < m; i++) {
			cin >> b[i];
		}
		sort(b.begin(), b.end());

		int ans = 0;
		for (int i = 0; i < n; i++) {
			ans += lower_bound(b.begin(), b.end(), a[i]) - b.begin();
		}
		cout << ans << '\n';
	}

	return 0;
}