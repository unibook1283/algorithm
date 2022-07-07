#include <iostream>
#include <cstring>
using namespace std;
const int MOD = 1000000007;
int cache[101];
int go(int n) {
	if (n <= 1) return 1;
	int& ret = cache[n];
	if (ret != -1) return ret;
	return ret = (go(n - 1) + go(n - 2)) % MOD;
}
int assymetric(int width) {
	if (width % 2 == 1) {
		return (go(width) - go(width / 2)) % MOD;
	}
	int ret = go(width) % MOD;
	ret = (ret - go(width / 2 - 1) + MOD) % MOD;
	ret = (ret - go(width / 2) + MOD) % MOD;
	return ret;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		memset(cache, -1, sizeof(cache));
		int n;
		cin >> n;
		cout << assymetric(n) << '\n';
	}




	return 0;
}