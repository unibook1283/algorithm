#include <iostream>
#include <vector>
using namespace std;
int parent[100001];
int a[100001];
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
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n, m, q;
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		parent[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		union_parent(x, y);
	}

	vector<pair<int, int>> water(n + 1);	// (1, 0)
	for (int i = 1; i <= n; i++) {
		int root = get_parent(i);
		if (a[i] == 1) {
			water[root].first++;
		}
		else {
			water[root].second++;
		}
	}
	while (q--) {
		int num;
		cin >> num;
		int root = get_parent(num);
		int clean = water[root].first;
		int dirty = water[root].second;
		cout << (clean > dirty) << '\n';
	}



	return 0;
}