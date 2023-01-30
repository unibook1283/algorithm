#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end(), greater<>());

	int ans = 0;
	for (int i = 0; i < k; i++) {
		ans += v[i];
		ans -= i;
	}
	cout << ans << '\n';

	return 0;
}