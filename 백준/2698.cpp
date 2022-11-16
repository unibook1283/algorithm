#include <iostream>
#include <cstring>
using namespace std;
int cache[101][101][2];
int go(int n, int k, int prev) {
	if (n == 0) {
		if (k == 0) return 1;
		return 0;
	}
	int& ret = cache[n][k][prev];
	if (ret != -1) return ret;
	ret = 0;
	if (prev == 0) {
		ret += go(n - 1, k, 0);
		ret += go(n - 1, k, 1);
	}
	else {
		ret += go(n - 1, k, 0);
		ret += go(n - 1, k - 1, 1);
	}
	return ret;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		memset(cache, -1, sizeof(cache));
		int n, k;
		cin >> n >> k;
		cout << go(n, k, false) << '\n';
	}

	return 0;
}