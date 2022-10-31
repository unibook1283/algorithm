#include <iostream>
#include <cstring>
using namespace std;
bool small[10000];
int cache[10000][150];
int n, m;
bool found = false;
int go(int index, int prev_v) {
	if (index == n) {
		found = true;
		return 0;
	}

	int& ret = cache[index][prev_v];
	if (ret != -1) return ret;

	ret = 987654321;
	for (int v = prev_v - 1; v <= prev_v + 1; v++) {
		if (v <= 0) continue;
		if (!small[index + v] && index + v <= n)
			ret = min(ret, 1 + go(index + v, v));
	}
	return ret;
}
int main() {
	memset(cache, -1, sizeof(cache));
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		small[num] = true;
	}
	int res = go(1, 0);
	if (found) cout << res << '\n';
	else cout << -1 << '\n';

	return 0;
}