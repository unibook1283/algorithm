#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int ans = 0;
	for (int i = n - 1; i > 0; i--) {
		int dif = v[i - 1] - v[i];
		if (dif >= 0) {
			v[i - 1] -= dif + 1;
			ans += dif + 1;
		}
	}
	cout << ans << '\n';

	return 0;
}