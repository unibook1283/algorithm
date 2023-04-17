#include <iostream>
#include <cstring>
using namespace std;
int v[2001];
int cache[2001][2001];
int n;
int go(int left, int right) {
	if (left == right) {
		return n * v[left];
	}
	int order = left + (n - right);
	int& ret = cache[left][right];
	if (ret != -1) return ret;
	ret = 0;
	ret = max(ret, order * v[left] + go(left + 1, right));
	ret = max(ret, order * v[right] + go(left, right - 1));
	return ret;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	memset(cache, -1, sizeof(cache));
	cout << go(0, n - 1) << '\n';

	return 0;
}