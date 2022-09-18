#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int d[10001];
int main() {
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> v[10001];
	for (int i = 0; i < n; i++) {
		int from, to, dist;
		cin >> from >> to >> dist;
		v[to].push_back(make_pair(from, dist));
	}

	for (int i = 1; i <= m; i++) {
		d[i] = 987654321;
	}
	d[0] = 0;
	for (int i = 1; i <= m; i++) {
		if (v[i].empty()) d[i] = d[i - 1] + 1;
		else {
			for (int j = 0; j < v[i].size(); j++) {
				d[i] = min(min(d[i], d[i - 1] + 1), d[v[i][j].first] + v[i][j].second);
			}
		}
	}
	cout << d[m] << '\n';

	return 0;
}