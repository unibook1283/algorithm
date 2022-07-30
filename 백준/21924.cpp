#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, pair<int, int>>> v;
int parent[100001];
int get_parent(int x) {
	if (parent[x] == x) return x;
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
	if (x == y) return true;
	return false;
}
int main() {
	int n, m;
	long long total = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back(make_pair(c, make_pair(a, b)));
		total += c;
	}
	sort(v.begin(), v.end());

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	long long cost = 0;
	for (int i = 0; i < m; i++) {
		auto p = v[i];
		int c = p.first;
		int a = p.second.first;
		int b = p.second.second;
		if (!same_parent(a, b)) {
			union_parent(a, b);
			cost += c;
		}
	}

	int p = get_parent(1);
	for (int i = 1; i < n; i++) {
		if (get_parent(i) != p) {
			cout << -1;
			return 0;
		}
	}

	cout << total - cost << '\n';


	return 0;
}