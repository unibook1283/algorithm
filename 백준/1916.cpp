#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<pair<int, int>> v[1001];	// (목적지, 비용)
int d[1001];
void dijkstra(int x) {
	d[x] = 0;
	priority_queue<pair<int, int>> pq;	// (-비용, 목적지)
	pq.push(make_pair(0, x));
	while (!pq.empty()) {
		x = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();
		if (d[x] < cost) continue;
		for (int i = 0; i < v[x].size(); i++) {
			auto p = v[x][i];
			int nx = p.first;
			int ncost = p.second + cost;
			if (d[nx] > ncost) {
				d[nx] = ncost;
				pq.push(make_pair(-ncost, nx));
			}
		}
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		v[from].push_back(make_pair(to, cost));
	}
	int start, end;
	cin >> start >> end;

	for (int i = 1; i <= n; i++) {
		d[i] = 987654321;
	}
	dijkstra(start);
	cout << d[end] << '\n';

	return 0;
}