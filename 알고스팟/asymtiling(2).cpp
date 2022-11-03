#include <iostream>
#include <cstring>
using namespace std;
int cache[101];
const int MOD = 1000000007;
int tiling(int width) {
	if (width <= 1) return 1;
	int& ret = cache[width];
	if (ret != -1) return ret;
	return ret = (tiling(width - 1) + tiling(width - 2)) % MOD;
}
int asymmetric(int width) {
	// width : È¦¼ö
	if (width % 2 == 1)
		return (tiling(width) - tiling(width / 2) + MOD) % MOD;
	// width : Â¦¼ö
	int ret = tiling(width);
	ret = (ret - tiling(width / 2 - 1) + MOD) % MOD;
	ret = (ret - tiling(width / 2) + MOD) % MOD;
	return ret;
}
int main() {
	int t;
	cin >> t;
	memset(cache, -1, sizeof(cache));
	while (t--) {
		int n;
		cin >> n;
		cout << asymmetric(n) << '\n';
	}

	return 0;
}