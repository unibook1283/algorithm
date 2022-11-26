#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<pair<int, pair<int, int>>> v;
	for (int i = 0; i < n; i++) {
		int s, e, c;
		cin >> s >> e >> c;
		v.push_back(make_pair(s, make_pair(e, c)));
	}
	sort(v.begin(), v.end());

	vector<pair<int, pair<int, int>>> ans;
	int l = v[0].first;
	int r = v[0].second.first;
	int cost = v[0].second.second;
	for (int i = 1; i < n; i++) {
		int s = v[i].first;
		int e = v[i].second.first;
		int c = v[i].second.second;
		if (r >= s) {
			r = max(r, e);
			cost = min(cost, c);
		}
		else {
			ans.push_back(make_pair(l, make_pair(r, cost)));
			l = s;
			r = e;
			cost = c;
		}
	}
	ans.push_back(make_pair(l, make_pair(r, cost)));

	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i].first << ' ' << ans[i].second.first << ' ' << ans[i].second.second << '\n';
	}

	return 0;
}