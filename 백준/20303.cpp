#include <iostream>
#include <map>
#include <vector>
#include <cstring>
using namespace std;
int n, m, k;
int candy[30001], parent[30001], cache[30001][3001];
vector<pair<int, int>> v;
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
int go(int index, int crying) {
	int v_size = v.size();
	if (index == v_size) {
		return 0;
	}
	int& ret = cache[index][crying];
	if (ret != -1) return ret;
	ret = 0;
	if (crying + v[index].first < k)
		ret = max(ret, v[index].second + go(index + 1, crying + v[index].first));
	ret = max(ret, go(index + 1, crying));
	return ret;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {
		cin >> candy[i];
	}

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	while (m--) {
		int a, b;
		cin >> a >> b;
		union_parent(a, b);
	}

	map<int, int> candy_count_of_group;	// (친구 그룹 parent, 캔디 개수)
	map<int, int> child_count_of_group;
	for (int i = 1; i <= n; i++) {
		candy_count_of_group[get_parent(i)] += candy[i];
		child_count_of_group[get_parent(i)]++;
	}

	for (auto p : candy_count_of_group) {
		v.push_back({ child_count_of_group[p.first], p.second });
	}

	memset(cache, -1, sizeof(cache));
	cout << go(0, 0) << '\n';

	return 0;
}