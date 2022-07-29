#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;
bool cmp(tuple<int, int, int>& u, tuple<int, int, int>& v) {
	int from_u, to_u, weight_u, from_v, to_v, weight_v;
	tie(from_u, to_u, weight_u) = u;
	tie(from_v, to_v, weight_v) = v;
	if (to_u == to_v) {
		return from_u > from_v;
	}
	return to_u < to_v;
}
int main() {
	int n, c, m;
	cin >> n >> c >> m;
	vector<tuple<int, int, int>> v;
	for (int i = 0; i < m; i++) {
		int from, to, weight;
		cin >> from >> to >> weight;
		v.push_back(make_tuple(from, to, weight));
	}
	sort(v.begin(), v.end(), cmp);

	vector<int> weight_in_town(n + 1, 0);
	int ans = 0;
	for (int i = 0; i < m; i++) {
		int from, to, weight;
		tie(from, to, weight) = v[i];
		int max_weight = weight;
		for (int j = from; j < to; j++) {
			max_weight = min(max_weight, c - weight_in_town[j]);
		}
		for (int j = from; j < to; j++) {
			weight_in_town[j] += max_weight;
		}
		ans += max_weight;
	}
	cout << ans << '\n';

	return 0;
}