#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> v;	// (xi, i)
	for (int i = 0; i < n; i++) {
		int xi;
		cin >> xi;
		v.push_back(make_pair(xi, i));
	}
	sort(v.begin(), v.end());
	
	vector<int> ans(n);
	int cnt = 0;
	for (int i = 1; i < n; i++) {
		if (v[i - 1].first != v[i].first)
			cnt++;
		ans[v[i].second] = cnt;
	}

	for (int i = 0; i < n; i++)
		cout << ans[i] << ' ';
	cout << '\n';

	return 0;
}