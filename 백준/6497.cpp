#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int parent[200001];
int get_parent(int x) {
	if (parent[x] == x) return x;
	return parent[x] = get_parent(parent[x]);
}
void union_parent(int x, int y) {
	x = get_parent(x);
	y = get_parent(y);
	if (x < y) parent[y] = x;
	else parent[x] = y;
}
bool same_parent(int x, int y) {
	x = get_parent(x);
	y = get_parent(y);
	if (x == y) return true;
	return false;
}
int main() {
	while (1) {
		int m, n;
		cin >> m >> n;
		if (m == 0 && n == 0) break;
		vector<pair<int, pair<int, int>>> v;
		int total_cost = 0;
		for (int i = 0; i < n; i++) {
			int x, y, z;
			cin >> x >> y >> z;
			v.push_back(make_pair(z, make_pair(x, y)));
			total_cost += z;
		}
		sort(v.begin(), v.end());

		for (int i = 0; i < m; i++) {
			parent[i] = i;
		}

		int ans = 0;
		for (int i = 0; i < n; i++) {
			auto p = v[i];
			int z = p.first;
			int x = p.second.first;
			int y = p.second.second;
			if (!same_parent(x, y)) {
				union_parent(x, y);
				ans += z;
			}
		}
		cout << total_cost - ans << '\n';
	}

	return 0;
}