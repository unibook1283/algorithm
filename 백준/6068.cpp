#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) return a.first > b.first;
	return a.second > b.second;
}
int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++) {
		int t, s;
		cin >> t >> s;
		v.push_back({ t,s });
	}
	sort(v.begin(), v.end(), compare);

	int prev_end_time = 1000001;
	for (int i = 0; i < v.size(); i++) {
		int t = v[i].first;
		int s = v[i].second;
		prev_end_time = min(prev_end_time - t, s - t);
	}
	if (prev_end_time < 0)
		cout << -1 << '\n';
	else
		cout << prev_end_time << '\n';

	return 0;
}