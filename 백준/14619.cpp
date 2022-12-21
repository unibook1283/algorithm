#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int h[101];
vector<int> v[101];
int cache[101][501];
int go(int here, int move) {
	if (move == 0) return h[here];
	int& ret = cache[here][move];
	if (ret != -1) return ret;
	ret = 987654321;
	for (int i = 0; i < v[here].size(); i++) {
		int there = v[here][i];
		ret = min(ret, go(there, move - 1));
	}
	return ret;
}
int main() {
	memset(cache, -1, sizeof(cache));
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> h[i];
	}
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	int t;
	cin >> t;
	while (t--) {
		int a, k;
		cin >> a >> k;
		if (v[a].empty()) {
			cout << "-1\n";
			continue;
		}
		cout << go(a, k) << '\n';
	}

	return 0;
}