#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
vector<int> v[20001];
int d[20001];
int max_d = 0;
void bfs(int x) {
	d[x] = 0;
	queue<int> q;
	q.push(x);
	while (!q.empty()) {
		x = q.front();
		q.pop();
		max_d = max(max_d, d[x]);
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
	int n, m;
	cin >> n >> m;
	memset(d, -1, sizeof(d));
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	bfs(1);
	int number = 987654321;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (d[i] == max_d) {
			cnt++;
			number = min(number, i);
		}
	}
	cout << number << ' ' << max_d << ' ' << cnt << '\n';

	return 0;
}