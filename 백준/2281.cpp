#include <iostream>
#include <cstring>
using namespace std;
int a[1001];
int cache[1001][1001];
int n, m;
int go(int index, int length) {
	if (index == n) {
		return 0;
	}
	int& ret = cache[index][length];
	if (ret != -1) return ret;
	ret = (m - length + 1) * (m - length + 1) + go(index + 1, a[index] + 1);
	if (length + a[index] <= m) {
		ret = min(ret, go(index + 1, length + a[index] + 1));
	}
	return ret;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	memset(cache, -1, sizeof(cache));
	cout << go(0, 0) << '\n';

	return 0;
}