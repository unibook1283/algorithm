#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n, k;
	cin >> n >> k;
	vector<int> v;
	int prev;
	cin >> prev;
	for (int i = 1; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num - prev);
		prev = num;
	}
	sort(v.begin(), v.end());
	int ans = 0;
	for (int i = 0; i < n - k; i++) {
		ans += v[i];
	}
	cout << ans << '\n';

	return 0;
}