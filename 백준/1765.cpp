#include <iostream>
#include <set>
using namespace std;
int parent[1001], enemy[1001];
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
int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {
		char op;
		int p, q;
		cin >> op >> p >> q;
		if (op == 'F') {
			union_parent(p, q);
		}
		else {
			if (enemy[p] != 0) {
				union_parent(enemy[p], q);
			}
			if (enemy[q] != 0) {
				union_parent(enemy[q], p);
			}
			enemy[p] = q;
			enemy[q] = p;
		}
	}

	set<int> parent_set;
	for (int i = 1; i <= n; i++) {
		parent_set.insert(parent[i]);
	}
	cout << parent_set.size() << '\n';

	return 0;
}