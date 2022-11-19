#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n;
int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int> v(n);
		priority_queue<pair<int, int>> pq;	// (price, index)
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			pq.push(make_pair(v[i], i));
		}
		int start_index = 0;
		long long ans = 0;
		while (!pq.empty()) {
			long long max_price = pq.top().first;
			int max_index = pq.top().second;
			pq.pop();
			for (int i = start_index; i < max_index; i++) {
				if (v[i] < max_price) ans += max_price - v[i];
				start_index = i + 1;
			}
			if (max_index == n - 1) break;
		}
		cout << ans << '\n';
	}

	return 0;
}