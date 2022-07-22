#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool check[10001];
bool cmp(pair<int, int>& a, pair<int, int>& b) {
	if (a.first == b.first) return a.second > b.second;
	return a.first > b.first;
}
int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);	// (p, d)
	for (int i = 0; i < n; i++) {
		int p, d;
		cin >> p >> d;
		v[i] = make_pair(p, d);
	}
	sort(v.begin(), v.end(), cmp);

	int ans = 0;
	for (int i = 0; i < n; i++) {
		int p = v[i].first;
		int d = v[i].second;
		for (int i = d; i > 0; i--) {
			if (!check[i]) {
				check[i] = true;
				ans += p;
				break;
			}
		}
	}
	cout << ans << '\n';

	return 0;
}