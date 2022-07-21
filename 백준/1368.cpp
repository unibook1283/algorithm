#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int parent[301];
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
	if (x==y) return true;
	return false;
}
int main() {
	int n;
	cin >> n;
	vector<pair<int, pair<int, int>>> v(n + 1);
	for (int i = 1; i <= n; i++) {
		int w;
		cin >> w;
		v.push_back(make_pair(w, make_pair(0, i)));
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int w;
			cin >> w;
			if (i < j) {
				v.push_back(make_pair(w, make_pair(i, j)));
			}
		}
	}
	sort(v.begin(), v.end());
	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}
	int ans = 0;
	for (int i = 0; i < v.size(); i++) {
		auto p = v[i];
		int c = p.first;
		int a = p.second.first;
		int b = p.second.second;
		if (!same_parent(a, b)) {
			union_parent(a, b);
			ans += c;
		}
	}
	cout << ans << '\n';


	return 0;
}