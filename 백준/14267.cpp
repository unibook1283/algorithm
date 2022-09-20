#include <iostream>
#include <vector>
using namespace std;
int a[100001];
int d[100001];
vector<int> v[100001];
void dfs(int x) {
	d[x] += a[x];
	for (int i = 0; i < v[x].size(); i++) {
		int nx = v[x][i];
		d[nx] += d[x];
		dfs(nx);
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int parent;
		cin >> parent;
		v[parent].push_back(i);
	}
	for (int i = 0; i < m; i++) {
		int x, w;
		cin >> x >> w;
		a[x] += w;
	}

	dfs(1);
	
	for (int i = 1; i <= n; i++) {
		cout << d[i] << ' ';
	}
	cout << '\n';
	
	return 0;
}