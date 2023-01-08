#include <iostream>
#include <queue>
using namespace std;
int a[1501][1501];
int n;
int bfs(priority_queue<pair<int, pair<int, int>>> pq) {
	int cnt = 0;
	while (!pq.empty()) {
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();
		cnt++;
		if (cnt == n) return a[x][y];
		int nx = x - 1;
		int ny = y;
		pq.push(make_pair(a[nx][ny], make_pair(nx, ny)));
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	priority_queue<pair<int, pair<int, int>>> pq;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (i == n - 1) {
				pq.push(make_pair(a[i][j], make_pair(i, j)));
			}
		}
	}
	cout << bfs(pq) << '\n';

	return 0;
}