#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(int u, int v) {
	return u > v;
}
int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end(), cmp);

	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, i + v[i]);
	}
	cout << ans + 2 << '\n';


	return 0;
}