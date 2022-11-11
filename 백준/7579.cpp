#include <iostream>
#include <cstring>
using namespace std;
int m[101];
int c[101];
int cache[101][10001];
int n, M;
int go(int index, int cost) {
	if (cost < 0) return 0;
	if (index == n) return 0;
	int& ret = cache[index][cost];
	if (ret != -1) return ret;
	ret = max(ret, go(index + 1, cost));
	if (cost - c[index] >= 0)
		ret = max(ret, m[index] + go(index + 1, cost - c[index]));
	return ret;
}
int main() {
	cin >> n >> M;
	for (int i = 0; i < n; i++)
		cin >> m[i];
	for (int i = 0; i < n; i++)
		cin >> c[i];

	memset(cache, -1, sizeof(cache));
	for (int i = 0; i < 10001; i++) {
		if (go(0, i) >= M) {
			cout << i << '\n';
			break;
		}
	}

	return 0;
}