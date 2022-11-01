#include <iostream>
#include <cstring>
using namespace std;
int cache[101];
int tiling(int n) {
	if (n <= 1) return 1;
	int& ret = cache[n];
	if (ret != -1) return ret;
	return ret = (tiling(n - 1) + tiling(n - 2)) % 1000000007;
}
int main() {
	int t;
	cin >> t;
	memset(cache, -1, sizeof(cache));
	while (t--) {
		int n;
		cin >> n;
		cout << tiling(n) << '\n';
	}

	return 0;
}