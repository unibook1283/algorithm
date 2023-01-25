#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MAX = 20001;
const int INF = 987654321;
vector<pair<int, int>> graph[MAX];	// (¸ñÀûÁö, cost)
int d[MAX];
void dijkstra(int k) {
	d[k] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, k));
	while (!pq.empty()) {
		int dist = -pq.top().first;
		int x = pq.top().second;
		pq.pop();
		for (int i = 0; i < graph[x].size(); i++) {
			int nx = graph[x][i].first;
			int ndist = dist + graph[x][i].second;
			if (d[nx] > ndist) {
				d[nx] = ndist;
				pq.push(make_pair(-ndist, nx));
			}
		}
	}
}
int main() {
	int v, e, k;
	cin >> v >> e >> k;
	for (int i = 0; i < e; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back(make_pair(v, w));
	}

	for (int i = 1; i <= v; i++)
		d[i] = INF;

	dijkstra(k);
	for (int i = 1; i <= v; i++) {
		if (d[i] == INF) cout << "INF\n";
		else cout << d[i] << '\n';
	}

	return 0;
}