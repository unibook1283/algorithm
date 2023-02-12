#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;
int n, m, k;
vector<pair<int, int>> graph[10001];	// (목적지, cost)
const long long INF = numeric_limits<long long>::max();
long long costs[10001][21];
void dijkstra() {
	costs[1][0] = 0;
	priority_queue<pair<long long, pair<int, int>>> pq;	// (cost, number, count)
	pq.push(make_pair(0, make_pair(1, 0)));
	while (!pq.empty()) {
		long long cost = -pq.top().first;
		int x = pq.top().second.first;
		int count = pq.top().second.second;
		pq.pop();
		if (cost > costs[x][count]) continue;
		for (int i = 0; i < graph[x].size(); i++) {
			int nx = graph[x][i].first;
			long long ncost = cost + graph[x][i].second;
			// 도로 포장 X
			if (ncost < costs[nx][count]) {
				costs[nx][count] = ncost;
				pq.push(make_pair(-ncost, make_pair(nx, count)));
			}
			// 도로 포장 O
			if (count + 1 <= k && cost < costs[nx][count + 1]) {
				costs[nx][count + 1] = cost;
				pq.push(make_pair(-cost, make_pair(nx, count + 1)));
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
		graph[b].push_back(make_pair(a, c));
	}

	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= k; j++)
			costs[i][j] = INF;

	dijkstra();

	long long ans = INF;
	for (int i = 0; i <= k; i++)
		ans = min(ans, costs[n][i]);
	cout << ans << '\n';

	return 0;
}