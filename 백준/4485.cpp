#include <iostream>
#include <queue>
using namespace std;
int a[130][130];
int d[130][130];
int n;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
void dijkstra() {
	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push(make_pair(-a[0][0], make_pair(0, 0)));
	d[0][0] = a[0][0];

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
				int ncost = cost + a[nx][ny];
				if (ncost < d[nx][ny]) {
					d[nx][ny] = ncost;
					pq.push(make_pair(-ncost, make_pair(nx, ny)));
				}
			}
		}
	}
}
int main() {
	int t = 0;
	while (1) {
		t++;
		cin >> n;
		if (n == 0) break;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
				d[i][j] = 987654321;
			}
		}
		dijkstra();
		cout << "Problem " << t << ": " << d[n - 1][n - 1] << '\n';
	}

	return 0;
}