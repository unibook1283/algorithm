#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}
	sort(v.begin(), v.end());
	int l, p;
	cin >> l >> p;

	priority_queue<int> pq;
	int i = 0;
	int ans = 0;
	while (1) {
		while (i < n && v[i].first <= p) {
			pq.push(v[i++].second);
		}
		if (p < l) {
			if (!pq.empty()) {
				p += pq.top();
				pq.pop();
				ans++;
			}
			else {
				ans = -1;
				break;
			}
		}
		else break;
	}
	cout << ans << '\n';

	return 0;
}