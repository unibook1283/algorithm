#include <iostream>
using namespace std;
int a[10001];
int parent[10001];
int min_cost[10001];
const int INF = 987654321;
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
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		parent[i] = i;
		min_cost[i] = INF;
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		union_parent(a, b);
	}

	for (int i = 0; i < n; i++) {
		int parent = get_parent(i);
		min_cost[parent] = min(min_cost[parent], a[i]);
	}
	int sum = 0;
	for (int i = 0; i < n; i++) {
		int c = min_cost[i];
		if (c != INF) sum += c;
	}
	
	if (sum > k) cout << "Oh no\n";
	else cout << sum << '\n';


	return 0;
}