#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<pair<int, int>> v;
		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			v.push_back({ a,b });
		}
		sort(v.begin(), v.end());

		int minSecondScore = 987654321;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (v[i].second < minSecondScore) {
				minSecondScore = v[i].second;
				ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}