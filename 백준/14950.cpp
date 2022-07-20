#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int parent[10001];
vector<pair<int, pair<int, int>>> v;
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
	int n, m, t;
	cin >> n >> m >> t;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back(make_pair(c, make_pair(a, b)));
	}
	sort(v.begin(), v.end());
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	int ans = 0;
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		auto p = v[i];
		int c = p.first;
		int a = p.second.first;
		int b = p.second.second;
		if (!same_parent(a, b)) {
			union_parent(a, b);
			ans += c + t * cnt++;
		}
	}
	cout << ans << '\n';


	return 0;
}