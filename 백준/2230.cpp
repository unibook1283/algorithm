#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end());

	int left = 0, right = 0;
	int ans = 2000000001;
	while (left < n && right < n) {
		int diff = v[right] - v[left];
		if (diff >= m) {
			ans = min(ans, diff);
			left++;
		}
		else right++;
	}
	cout << ans << '\n';

	return 0;
}