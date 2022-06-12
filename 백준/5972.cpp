#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
using namespace std; 
vector<pair<int, int>> v[50001];	// (c, b)
int d[50001];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back(make_pair(c, b));
		v[b].push_back(make_pair(c, a));
	}
	for (int i = 1; i <= n; i++) {
		d[i] = 987654321;
	}
	
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, 1));
	while (!pq.empty()) {
		int c = -pq.top().first;
		int b = pq.top().second;
		pq.pop();
		for (int i = 0; i < v[b].size(); i++) {
			int nc = v[b][i].first;
			int nb = v[b][i].second;
			if (d[nb] > c + nc) {
				d[nb] = c + nc;
				pq.push(make_pair(-d[nb], nb));
			}
		}
	}
	cout << d[n];

	return 0;
}