#include <iostream>
#include <vector>
using namespace std;
bool cats[100001];
vector<int> graph[100001];
bool check[100001];
int n, m;
int dfs(int x, int consecutive_cat_count) {
	if (consecutive_cat_count > m) return 0;
	if (x != 1 && graph[x].size() == 1) return 1;
	int ret = 0;
	for (int nx : graph[x]) {
		if (!check[nx]) {
			check[nx] = true;
			if (cats[nx]) ret += dfs(nx, consecutive_cat_count + 1);
			else ret += dfs(nx, 0);
		}
	}
	return ret;
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> cats[i];
	}
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	check[1] = true;
	cout << dfs(1, cats[1]) << '\n';

	return 0;
}