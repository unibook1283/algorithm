#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> graph[100001];
int d[100001];
void bfs(int x) {
	int cnt = 1;
	d[x] = cnt++;
	queue<int> q;
	q.push(x);
	while (!q.empty()) {
		x = q.front();
		q.pop();
		for (int i = 0; i < graph[x].size(); i++) {
			int nx = graph[x][i];
			if (d[nx] == 0) {
				d[nx] = cnt++;
				q.push(nx);
			}
		}
	}
}
int main() {
	int n, m, r;
	cin >> n >> m >> r;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}
	bfs(r);
	for (int i = 1; i <= n; i++) {
		cout << d[i] << '\n';
	}


	return 0;
}