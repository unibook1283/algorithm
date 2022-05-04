#include <iostream>
using namespace std;
int cal(int x) {
	if (x == 0) return 1;
	if (x % 10 == 0) {
		return 1 + cal(x / 10);
	}
	else if (x / 10 != 0) {
		return cal(x / 10);
	}
	return 0;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		int ans = 0;
		for (int i = n; i <= m; i++) {
			ans += cal(i);
		}
		cout << ans << '\n';
	}

	return 0;
}