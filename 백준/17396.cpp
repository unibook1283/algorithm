#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n, m;
int a[100001];
bool visit[100001];
long long d[100001];
vector<pair<int, int>> v[100001];	// (목적지, 시간)
void dijkstra(int x) {
	d[x] = 0;
	priority_queue<pair<long long, int>> pq;	// (-현재 노드까지 시간, 노드)
	pq.push(make_pair(0, x));
	while (!pq.empty()) {
		long long cost = -pq.top().first;
		x = pq.top().second;
		pq.pop();
		if (visit[x]) continue;
		visit[x] = true;
		for (int i = 0; i < v[x].size(); i++) {
			int nx = v[x][i].first;
			int ncost = v[x][i].second;
			if (a[nx] == 1 && nx != n - 1) continue;
			if (d[nx] > cost + ncost) {
				d[nx] = cost + ncost;
				pq.push(make_pair(-d[nx], nx));
			}
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		d[i] = 99987654321;
	}
	for (int i = 0; i < m; i++) {
		int a, b, t;
		cin >> a >> b >> t;
		v[a].push_back(make_pair(b, t));
		v[b].push_back(make_pair(a, t));
	}

	dijkstra(0);

	if (d[n - 1] == 99987654321) cout << -1 << '\n';
	else cout << d[n - 1];

	return 0;
}