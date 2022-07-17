#include <iostream>
using namespace std;
int parent[500001];
int get_parent(int x) {
	if (x == parent[x]) return x;
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
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		if (same_parent(a, b)) {
			cout << i << '\n';
			return 0;
		}
		union_parent(a, b);
	}
	cout << 0 << '\n';

	return 0;
}