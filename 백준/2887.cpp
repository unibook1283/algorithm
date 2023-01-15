#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int>> v[3];	// (ÁÂÇ¥, index)
vector<pair<int, pair<int, int>>> edge;	// (°Å¸®, a_index, b_index)
int parent[100001];
int get_parent(int x) {
	if (x == parent[x]) return x;
	return parent[x] = get_parent(parent[x]);
}
void union_parent(int x, int y) {
	x = get_parent(x);
	y = get_parent(y);
	if (x > y) parent[y] = x;
	else parent[x] = y;
}
bool same_parent(int x, int y) {
	x = get_parent(x);
	y = get_parent(y);
	return x == y;
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		v[0].push_back(make_pair(x, i));
		v[1].push_back(make_pair(y, i));
		v[2].push_back(make_pair(z, i));
	}
	sort(v[0].begin(), v[0].end());
	sort(v[1].begin(), v[1].end());
	sort(v[2].begin(), v[2].end());

	for (int i = 0; i < n - 1; i++) {
		edge.push_back(make_pair(v[0][i + 1].first - v[0][i].first, make_pair(v[0][i].second, v[0][i + 1].second)));
		edge.push_back(make_pair(v[1][i + 1].first - v[1][i].first, make_pair(v[1][i].second, v[1][i + 1].second)));
		edge.push_back(make_pair(v[2][i + 1].first - v[2][i].first, make_pair(v[2][i].second, v[2][i + 1].second)));
	}

	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}

	sort(edge.begin(), edge.end());
	int ans = 0;
	for (int i = 0; i < edge.size(); i++) {
		int cost = edge[i].first;
		int a = edge[i].second.first;
		int b = edge[i].second.second;
		if (!same_parent(a, b)) {
			union_parent(a, b);
			ans += cost;
		}
	}
	cout << ans << '\n';

	return 0;
}