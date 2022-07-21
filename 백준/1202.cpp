#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> gems(n);
	for (int i = 0; i < n; i++) {
		long long m, v;
		cin >> m >> v;
		gems[i] = make_pair(m, v);
	}
	sort(gems.begin(), gems.end());
	vector<int> c(k);
	for (int i = 0; i < k; i++) {
		cin >> c[i];
	}
	sort(c.begin(), c.end());
	
	long long ans = 0;
	priority_queue<long long> pq;
	for (int i = 0, j = 0; i < k; i++) {
		while (j < n && c[i] >= gems[j].first) {
			pq.push(gems[j++].second);
		}
		if (!pq.empty()) {
			ans += pq.top();
			pq.pop();
		}
	}
	cout << ans << '\n';

	return 0;
}