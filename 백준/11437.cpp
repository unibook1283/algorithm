#include <iostream>
#include <vector>
using namespace std;
vector<int> graph[50001];
int parent[50001];
bool check[50001];
int depth[50001];
void dfs(int x, int d) {
	check[x] = true;
	depth[x] = d;
	for (int i = 0; i < graph[x].size(); i++) {
		int nx = graph[x][i];
		if (check[nx]) continue;
		parent[nx] = x;
		dfs(nx, d + 1);
	}
}
int lca(int a, int b) {
	int min_d = min(depth[a], depth[b]);
	while (depth[a] != min_d)
		a = parent[a];
	while (depth[b] != min_d)
		b = parent[b];
	while (a != b) {
		a = parent[a];
		b = parent[b];
	}
	return a;
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	dfs(1, 0);

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout << lca(a, b) << '\n';
	}

	return 0;
}