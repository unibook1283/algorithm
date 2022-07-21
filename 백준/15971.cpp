#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int d[100001];
int maxi = 0;
void bfs(int x, int goal, vector<vector<pair<int, int>>> &v) {
	d[x] = 0;
	queue<int> q;
	q.push(x);
	while (!q.empty()) {
		x = q.front();
		q.pop();
		if (x == goal) return;
		for (int i = 0; i < v[x].size(); i++) {
			int nx = v[x][i].first;
			int cost = v[x][i].second;
			if (d[nx] == -1) {
				d[nx] = d[x] + cost;
				q.push(nx);
			}
		}
	}
}
void find_max(int to, int from, vector<vector<pair<int, int>>>& v) {
	queue<int> q;
	q.push(to);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		if (x == from) return;
		for (int i = 0; i < v[x].size(); i++) {
			int nx = v[x][i].first;
			int cost = v[x][i].second;
			if (d[nx] == d[x] - cost) {
				maxi = max(maxi, cost);
				q.push(nx);
			}
		}
	}
}
int main() {
	int n, from, to;
	cin >> n >> from >> to;
	vector<vector<pair<int, int>>> v(n + 1);	// (¸ñÀûÁö, cost)
	for (int i = 0; i < n - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back(make_pair(b, c));
		v[b].push_back(make_pair(a, c));
	}
	memset(d, -1, sizeof(d));
	bfs(from, to, v);
	find_max(to, from, v);
	cout << d[to] - maxi << '\n';

	return 0;
}