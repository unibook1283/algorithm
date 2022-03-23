#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
int n, m;
int d[101];
int v[101];
int bfs(int x) {
	queue<int> q;
	q.push(x);
	d[x] = 0;
	while (!q.empty()) {
		x = q.front();
		q.pop();
		if (x == 100) return d[x];
		for (int i = 1; i <= 6; i++) {
			int nx = x + i;
			if (nx > 100) break;
			if (d[nx] == -1) {
				d[nx] = d[x] + 1;
				if (v[nx] != 0) {
					int nnx = v[nx];
					if (d[nnx] == -1) {
						d[nnx] = d[nx];
						q.push(nnx);
					}
				}
				else q.push(nx);
			}
		}
		// 도착한 칸이 사다리면, 사다리를 타고 위로 올라간다.
		// 문제의 표현을 충실히 따르는게 좋을 수 있구나 이렇게.

		/*
		if (!v[x].empty()) {
			for (int i = 0; i < v[x].size(); i++) {
				int nx = v[x][i];
				if (d[nx] == -1) {
					d[nx] = d[x];
					q.push(nx);
				}
			}
		}
		else {
			for (int i = 1; i <= 6; i++) {
				int nx = x + i;
				if (nx > 100) break;
				if (d[nx] == -1) {
					d[nx] = d[x] + 1;
					q.push(nx);
				}
			}
		}
		*/
	}
	return -1;
}
int main() {
	memset(d, -1, sizeof(d));
	cin >> n >> m;
	int t = n + m;
	while (t--) {
		int from, to;
		cin >> from >> to;
		v[from] = to;
	}
	cout << bfs(1);


	return 0;
}