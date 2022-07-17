#include <iostream>
using namespace std;
int parent[1000001];
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
	if (x == y) return true;
	return false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int op, x, y;
		cin >> op >> x >> y;
		if (op == 0) {
			union_parent(x, y);
		}
		else if (op == 1) {
			if (same_parent(x, y)) {
				cout << "YES\n";
			}
			else cout << "NO\n";
		}
	}

	return 0;
}