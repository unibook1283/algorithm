#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
		}
		sort(v[i].begin(), v[i].end());
	}

	priority_queue<pair<int, pair<int, int>>> pq;	// (-value, row, col)
	int maxi = 0;
	for (int i = 0; i < n; i++) {
		pq.push({ -v[i][0], {i, 0} });
		maxi = max(maxi, v[i][0]);
	}
	int ans = 987654321;
	while (1) {
		int smallest = -pq.top().first;
		ans = min(ans, maxi - smallest);
		int row = pq.top().second.first;
		int col = pq.top().second.second;
		pq.pop();
		if (col == m - 1) break;
		maxi = max(maxi, v[row][col + 1]);
		pq.push({ -v[row][col + 1], {row, col + 1} });

	}
	cout << ans << '\n';

	return 0;
}