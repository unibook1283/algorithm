#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
vector<int> v[1001];
int d[1001];
int a, b, n, m;
int ans = -1;
void bfs(int x) {
	d[x] = 0;
	queue<int> q;
	q.push(x);
	while (!q.empty()) {
		x = q.front();
		q.pop();
		if (x == b) {
			ans = d[x];
			return;
		}
		for (int i = 0; i < v[x].size(); i++) {
			int nx = v[x][i];
			if (d[nx] == -1) {
				d[nx] = d[x] + 1;
				q.push(nx);
			}
		}
	}
}
int main() {
	cin >> a >> b;
	cin >> n >> m;
	while (m--) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	memset(d, -1, sizeof(d));
	bfs(a);

	cout << ans << '\n';


	return 0;
}