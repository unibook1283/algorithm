#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<vector<int>> a(n, vector<int>(4));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> a[i][j];
		}
	}
	vector<int> ab, cd;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ab.push_back(a[i][0] + a[j][1]);
			cd.push_back(a[i][2] + a[j][3]);
		}
	}
	sort(cd.begin(), cd.end());

	long long ans = 0;
	for (int i = 0; i < n * n; i++) {
		ans += upper_bound(cd.begin(), cd.end(), -ab[i]) - lower_bound(cd.begin(), cd.end(), -ab[i]);
	}
	cout << ans << '\n';

	return 0;
}