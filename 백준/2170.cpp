#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 1987654321;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}
	sort(v.begin(), v.end());

	int start = -INF;
	int end = -INF;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int x = v[i].first;
		int y = v[i].second;
		if (end >= x) {
			end = max(end, y);
		}
		else {
			ans += end - start;
			start = x;
			end = y;
		}
	}
	ans += end - start;
	cout << ans << '\n';

	return 0;
}