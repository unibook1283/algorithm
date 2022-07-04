#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int a[201][201];
bool check[201][201];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int n, k, s, ex, ey;
bool all_queue_empty(vector<queue<pair<int, int>>>& q) {
	for (int i = 1; i <= k; i++) {
		if (!q[i].empty()) return false;
	}
	return true;
}
int main() {
	cin >> n >> k;
	vector<queue<pair<int, int>>> q(k + 1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (a[i][j] != 0) q[a[i][j]].push(make_pair(i, j));
		}
	}
	cin >> s >> ex >> ey;
	ex--; ey--;

	while (s-- && !all_queue_empty(q)) {
		for (int i = 1; i <= k; i++) {
			int cnt = q[i].size();
			while (cnt--) {
				int x = q[i].front().first;
				int y = q[i].front().second;
				q[i].pop();
				int type = a[x][y];
				for (int j = 0; j < 4; j++) {
					int nx = x + dx[j];
					int ny = y + dy[j];
					if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
						if (a[nx][ny] == 0 && !check[nx][ny]) {
							a[nx][ny] = type;
							check[nx][ny] = true;
							q[i].push(make_pair(nx, ny));
						}
					}
				}
			}
			
		}
	}

	cout << a[ex][ey] << '\n';

	return 0;
}