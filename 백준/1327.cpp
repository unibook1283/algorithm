#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <map>
using namespace std;
int d[40321]; // 8!
int n, k;
map<vector<int>, int> m;
void initOrderMap(int n) {
	vector<int> v;
	for (int i = 1; i <= n; i++) {
		v.push_back(i);
	}
	int order = 0;
	do {
		m[v] = order++;
	} while (next_permutation(v.begin(), v.end()));
}
int bfs(vector<int> v) {
	int order = m[v];
	d[order] = 0;
	queue<vector<int>> q;
	q.push(v);
	while (!q.empty()) {
		v = q.front();
		q.pop();
		int prevOrder = m[v];
		if (prevOrder == 0) {
			return d[prevOrder];
		}
		for (int i = 0; i <= n - k; i++) {
			vector<int> temp = v;
			reverse(temp.begin() + i, temp.begin() + i + k);
			int order = m[temp];
			if (d[order] == -1) {
				d[order] = d[prevOrder] + 1;
				q.push(temp);
			}
		}
	}
	return -1;
}
int main() {
	cin >> n >> k;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	initOrderMap(n);

	memset(d, -1, sizeof(d));
	d[m[v]] = 0;

	cout << bfs(v) << '\n';

	return 0;
}