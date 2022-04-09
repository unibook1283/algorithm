#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <cstring>
#include <algorithm>
using namespace std;
int d[61][61][61];
int main() {
	int n;
	cin >> n;
	vector<int> a(3);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	queue<tuple<int, int, int>> q;
	q.push(make_tuple(a[0], a[1], a[2]));
	memset(d, -1, sizeof(d));
	vector<int> v(3);
	v = { 1,3,9 };
	d[a[0]][a[1]][a[2]] = 0;
	int ans;
	while (!q.empty()) {
		int x, y, z;
		tie(x, y, z) = q.front();
		q.pop();
		if (x == 0 && y == 0 && z == 0) break;
		do {
			int nx = x - v[0];
			int ny = y - v[1];
			int nz = z - v[2];
			if (nx < 0) nx = 0;
			if (ny < 0) ny = 0;
			if (nz < 0) nz = 0;
			if (d[nx][ny][nz] == -1) {
				d[nx][ny][nz] = d[x][y][z] + 1;
				q.push(make_tuple(nx, ny, nz));
			}
		} while (next_permutation(v.begin(), v.end()));
	}
	cout << d[0][0][0] << '\n';

	return 0;
}
/*
다이나믹으로 많이 풀던데, bfs + 순열로 풀어봄.
*/