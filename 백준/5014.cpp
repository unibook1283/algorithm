#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int f, s, g, u, d;
int dist[1000001];
void bfs(int x) {
	dist[x] = 0;
	queue<int> q;
	q.push(x);
	while (!q.empty()) {
		x = q.front();
		q.pop();
		if (x == g) return;
		int nx = x + u;
		if (nx >= 1 && nx <= f && dist[nx] == -1) {
			dist[nx] = dist[x] + 1;
			q.push(nx);
		}
		nx = x - d;
		if (nx >= 1 && nx <= f && dist[nx] == -1) {
			dist[nx] = dist[x] + 1;
			q.push(nx);
		}
	}
}
int main() {
	cin >> f >> s >> g >> u >> d;
	memset(dist, -1, sizeof(dist));
	bfs(s);
	if (dist[g] == -1) cout << "use the stairs\n";
	else cout << dist[g] << '\n';

	return 0;
}