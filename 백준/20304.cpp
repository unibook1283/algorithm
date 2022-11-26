#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int a[100001];
int d[1000001];
int n, m;
int get_max_bit_size(int n) {
	if (n == 0) return 1;
	int max_size = 0;
	while (n) {
		max_size++;
		n /= 2;
	}
	return max_size;
}
int bfs(int max_bit_size) {
	memset(d, -1, sizeof(d));
	queue<int> q;
	for (int i = 0; i < m; i++) {
		q.push(a[i]);
		d[a[i]] = 0;
	}
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < max_bit_size; i++) {
			int nx = x ^ (1 << i);
			if (nx <= n && d[nx] == -1) {
				d[nx] = d[x] + 1;
				q.push(nx);
			}
		}
	}
	int ret = 0;
	for (int i = 0; i <= n; i++) {
		ret = max(ret, d[i]);
	}
	return ret;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a[i];
	}
	int max_bit_size = get_max_bit_size(n);

	cout << bfs(max_bit_size) << '\n';

	return 0;
}