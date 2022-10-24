#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());

	long long ans = 0;
	for (int i = 0; i < a.size(); i++) {
		ans += abs(i + 1 - a[i]);
	}
	cout << ans << '\n';

	return 0;
}