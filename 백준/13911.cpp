#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<pair<int, int>> graph[10010];	// (格利瘤, 芭府)
int mac[10010], star[10010];
int dist[10010][2];
bool store[10010];
const int INF = 987654321;
void dijkstra(int x, int index) {
	dist[x][index] = 0;
	priority_queue<pair<int, int>> pq;	// (芭府, 格利瘤)
	pq.push({ 0, x });
	while (!pq.empty()) {
		int cost = -pq.top().first;
		x = pq.top().second;
		pq.pop();
		for (int i = 0; i < graph[x].size(); i++) {
			int nx = graph[x][i].first;
			int ncost = cost + graph[x][i].second;
			if (ncost < dist[nx][index]) {
				dist[nx][index] = ncost;
				pq.push({ -ncost, nx });
			}
		}
	}
}
int main() {
	int V, E;
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({ v,w });
		graph[v].push_back({ u,w });
	}
	int m, x, s, y;
	cin >> m >> x;
	for (int i = 0; i < m; i++) {
		cin >> mac[i];
		store[mac[i]] = true;
		graph[V + 1].push_back({ mac[i], 0 });
	}
	cin >> s >> y;
	for (int i = 0; i < s; i++) {
		cin >> star[i];
		store[star[i]] = true;
		graph[V + 2].push_back({ star[i],0 });
	}

	for (int i = 1; i <= V + 2; i++) {
		for (int j = 0; j < 2; j++) {
			dist[i][j] = INF;
		}
	}

	dijkstra(V + 1, 0);
	dijkstra(V + 2, 1);

	int ans = -1;
	for (int i = 1; i <= V; i++) {
		if (store[i]) continue;
		if (dist[i][0] > x || dist[i][1] > y) continue;
		int sum = dist[i][0] + dist[i][1];
		if (ans == -1 || ans > sum) {
			ans = sum;
		}
	}
	cout << ans << '\n';

	return 0;
}