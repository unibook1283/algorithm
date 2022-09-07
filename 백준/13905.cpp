#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int parent[100001];
int d[100001];
vector<pair<int, pair<int, int>>> v;
vector<pair<int, int>> graph[100001];
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
bool cmp(pair<int, pair<int, int>> u, pair<int, pair<int, int>> v) {
	return u.first > v.first;
}
int bfs(int s, int e) {
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		if (x == e) return d[x];
		for (int i = 0; i < graph[x].size(); i++) {
			auto p = graph[x][i];
			int nx = p.first;
			int cost = p.second;
			if (d[nx] == -1) {
				if (d[x] == -1 || cost < d[x]) d[nx] = cost;
				else d[nx] = d[x];
				q.push(nx);
			}
		}
	}
	return 0;
}
int main() {
	int n, m;
	cin >> n >> m;
	int s, e;
	cin >> s >> e;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back(make_pair(c, make_pair(a, b)));
	}
	sort(v.begin(), v.end(), cmp);

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
		d[i] = -1;
	}

	for (int i = 0; i < m; i++) {
		auto p = v[i];
		int a = p.second.first;
		int b = p.second.second;
		int c = p.first;
		if (!same_parent(a, b)) {
			union_parent(a, b);
			graph[a].push_back(make_pair(b, c));
			graph[b].push_back(make_pair(a, c));
		}
	}
	cout << bfs(s, e) << '\n';

	return 0;
}