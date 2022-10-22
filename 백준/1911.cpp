#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n, l;
	cin >> n >> l;
	vector<pair<int, int>> woong(n);
	for (int i = 0; i < n; i++) {
		int from, to;
		cin >> from >> to;
		woong[i] = make_pair(from, to);
	}
	sort(woong.begin(), woong.end());
	int p = 0, ans = 0;
	for (int i = 0; i < woong.size(); i++) {
		int from = woong[i].first;
		int to = woong[i].second;
		p = max(p, from);
		while (p < to) {
			p += l;
			ans++;
		}
	}
	cout << ans << '\n';

	return 0;
}