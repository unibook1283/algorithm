#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define INF 987654321
using namespace std;
vector<pair<int, int>> v[10001];	// (다음 컴퓨터 번호, 의존성)
int dist[10001];
void dijkstra(int x) {
	dist[x] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, x));
	while (!pq.empty()) {
		int cost = -pq.top().first;
		x = pq.top().second;
		pq.pop();
		for (int i = 0; i < v[x].size(); i++) {
			int nx = v[x][i].first;
			int ncost = v[x][i].second;
			//cout << nx << '\n';
			if (dist[nx] > cost + ncost) {
				dist[nx] = cost + ncost;
				pq.push(make_pair(-dist[nx], nx));
			}
		}
	}
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, d, c;
		cin >> n >> d >> c;
		for (int i = 0; i < d; i++) {
			int a, b, s;
			cin >> a >> b >> s;
			v[b].push_back(make_pair(a, s));
		}
		for (int i = 1; i <= n; i++) {
			dist[i] = INF;
		}
		dijkstra(c);
		int maxi = 0;
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (dist[i] != INF) {
				cnt++;
				maxi = max(maxi, dist[i]);
			}
		}
		cout << cnt << ' ' << maxi << '\n';
		for (int i = 1; i <= n; i++) {
			vector<pair<int, int>>().swap(v[i]);
		}
	}




	return 0;
}