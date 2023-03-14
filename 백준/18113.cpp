#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n, k, m;
	int maxi = 0;
	cin >> n >> k >> m;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		maxi = max(maxi, x);
		if (x - 2 * k >= 0) {
			v.push_back(x - 2 * k);
		}
		else if (x - k > 0) {
			v.push_back(x - k);
		}
	}

	int left = 1, right = maxi;
	int ans = -1;
	while (left <= right) {
		int mid = (left + right) / 2;
		int cnt = 0;
		for (int i = 0; i < v.size(); i++) {
			cnt += v[i] / mid;
		}
		if (cnt >= m) {
			ans = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	cout << ans << '\n';

	return 0;
}