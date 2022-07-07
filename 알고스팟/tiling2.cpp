#include <iostream>
#include <cstring>
using namespace std;
const int MOD = 1000000007;
int cache[101];
int go(int width) {
	if (width <= 1) return 1;
	int& ret = cache[width];
	if (ret != -1) return ret;
	return ret = (go(width - 1) + go(width - 2)) % MOD;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		memset(cache, -1, sizeof(cache));
		int n;
		cin >> n;
		cout << go(n) << '\n';
	}


	return 0;
}