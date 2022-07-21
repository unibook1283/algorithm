#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
int d[5001];
vector<pair<int, int>> v[5001];	// (格利瘤, cost)
const int INF = 987654321;
void dijkstra(int s) {
	d[s] = 0;
	priority_queue<pair<int, int>> pq;	// (-cost, 格利瘤)
	pq.push(make_pair(0, s));
	while (!pq.empty()) {
		int x = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();
		for (int i = 0; i < v[x].size(); i++) {
			int nx = v[x][i].first;
			int ncost = v[x][i].second;
			if (d[nx] > cost + ncost) {
				d[nx] = cost + ncost;
				pq.push(make_pair(-d[nx], nx));
			}
		}
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back(make_pair(b, c));
		v[b].push_back(make_pair(a, c));
	}
	int s, t;
	cin >> s >> t;
	for (int i = 1; i <= n; i++) {
		d[i] = INF;
	}
	dijkstra(s);
	cout << d[t] << '\n';

	return 0;
}