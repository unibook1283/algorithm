#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
pair<int, int> store[101];
int check[101];
int n;
int sx, sy, ex, ey;
bool bfs() {
	queue<pair<int, int>> q;
	q.push(make_pair(sx, sy));
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (abs(x - ex) + abs(y - ey) <= 1000) return true;
		for (int i = 0; i < n; i++) {
			if (check[i]) continue;
			int nx = store[i].first;
			int ny = store[i].second;
			if (abs(x - nx) + abs(y - ny) <= 1000) {
				check[i] = true;
				q.push(make_pair(nx, ny));
			}
		}
	}
	return false;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		memset(check, false, sizeof(check));
		cin >> n;
		cin >> sx >> sy;
		for (int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			store[i] = make_pair(x, y);
		}
		cin >> ex >> ey;
		if (bfs()) cout << "happy\n";
		else cout << "sad\n";
	}

	return 0;
}