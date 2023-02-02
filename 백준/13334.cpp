#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(pair<int, int> u, pair<int, int> v) {
	if (u.second == v.second)
		return u.first < v.first;
	return u.second < v.second;
}
int main() {
	int n, d;
	cin >> n;
	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++) {
		int h, o;
		cin >> h >> o;
		v.push_back(make_pair(min(h, o), max(h, o)));
	}
	cin >> d;
	sort(v.begin(), v.end(), cmp);

	priority_queue<int> pq;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int from = v[i].first;
		int to = v[i].second;
		if (to - from > d) continue;
		while (!pq.empty()) {
			if (to - (-pq.top()) > d) pq.pop();
			else break;
		}
		pq.push(-from);
		ans = max(ans, (int) pq.size());
	}
	cout << ans << '\n';

	return 0;
}