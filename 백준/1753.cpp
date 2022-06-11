#include <iostream>
#include <queue>
#include <vector>
#define MAX 20010
#define INF 987654321
using namespace std;
vector<pair<int, int>> a[MAX];	// (가중치, 목적지 정점)
int d[MAX];
int main() {
	int v, e, k;
	cin >> v >> e;
	cin >> k;
	for (int i = 0; i < e; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		a[u].push_back(make_pair(w, v));
	}
	for (int i = 1; i <= v; i++) {
		d[i] = INF;
	}

	d[k] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, k));
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int x = pq.top().second;
		pq.pop();
		for (int i = 0; i < a[x].size(); i++) {
			int ncost = a[x][i].first;
			int nx = a[x][i].second;
			if (d[nx] > cost + ncost) {
				d[nx] = cost + ncost;
				pq.push(make_pair(-d[nx], nx));
			}
		}
	}

	for (int i = 1; i <= v; i++) {
		if (d[i] == INF)
			cout << "INF\n";
		else 
			cout << d[i] << '\n';
	}


	return 0;
}