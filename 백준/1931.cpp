#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> order(n);
	for (int i = 0; i < n; i++) {
		int from, to;
		cin >> from >> to;
		order[i] = make_pair(to, from);
	}
	sort(order.begin(), order.end());
	
	int ans = 0, earliest = 0;
	for (int i = 0; i < n; i++) {
		int start = order[i].second;
		int end = order[i].first;
		if (earliest <= start) {
			ans++;
			earliest = end;
		}
	}

	cout << ans << '\n';

	return 0;
}