#include <iostream>
#include <cstring>
using namespace std;
const int MOD = 1000000007;
int cache[10001];
int m;
int go(int n) {
	if (n == 0) return 1;
	int& ret = cache[n];
	if (ret != -1) return ret;
	ret = 0;
	ret = (ret + go(n - 1)) % MOD;
	if (n - m >= 0)
		ret = (ret + go(n - m)) % MOD;
	return ret;
}
int main() {
	int n;
	cin >> n >> m;
	memset(cache, -1, sizeof(cache));
	cout << go(n) << '\n';

	return 0;
}