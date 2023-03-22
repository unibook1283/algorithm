#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
vector<int> v[300001];
int d[300001];
void bfs(int x) {
	d[x] = 0;
	queue<int> q;
	q.push(x);
	while (!q.empty()) {
		x = q.front();
		q.pop();
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
	int n, m, k, x;
	cin >> n >> m >> k >> x;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
	}

	memset(d, -1, sizeof(d));
	bfs(x);

	bool exist = false;
	for (int i = 1; i <= n; i++) {
		if (d[i] == k) {
			cout << i << '\n';
			exist = true;
		}
	}
	if (!exist) {
		cout << "-1\n";
	}

	return 0;
}