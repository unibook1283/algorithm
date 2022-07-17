#include <iostream>
using namespace std;
int parent[300001];
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
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < n - 2; i++) {
		int a, b;
		cin >> a >> b;
		union_parent(a, b);
	}
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (!same_parent(i, j)) {
				cout << i << ' ' << j << '\n';
				return 0;
			}
		}
	}


	return 0;
}