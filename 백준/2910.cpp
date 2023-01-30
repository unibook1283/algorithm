#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(pair<int, pair<int, int>> u, pair<int, pair<int, int>> v) {
	if (u.second.first == v.second.first) {
		return u.second.second < v.second.second;
	}
	return u.second.first > v.second.first;
}
int main() {
	int n, c;
	cin >> n >> c;
	map<int, pair<int, int>> m;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (m[x].first == 0) m[x] = make_pair(1, i);
		else m[x].first++;
	}

	vector<pair<int, pair<int, int>>> v(m.begin(), m.end());
	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++)
		for (int j = 0; j < v[i].second.first; j++)
			cout << v[i].first << ' ';
	cout << '\n';

	return 0;
}