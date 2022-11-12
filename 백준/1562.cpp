#include <iostream>
#include <cstring>
using namespace std;
int n;
int cache[101][10][(1 << 10)];
const int MOD = 1000000000;
long long go(int index, int prev, int check) {
	if (index == n - 1) return check == ((1 << 10) - 1);
	int& ret = cache[index][prev][check];
	if (ret != -1) return ret;
	ret = 0;
	if (prev - 1 >= 0)
		ret = (ret + go(index + 1, prev - 1, check | (1 << (prev - 1)))) % MOD;
	if (prev + 1 < 10)
		ret = (ret + go(index + 1, prev + 1, check | (1 << (prev + 1)))) % MOD;
	return ret;
}
int main() {
	cin >> n;
	long long ans = 0;
	memset(cache, -1, sizeof(cache));
	for (int i = 1; i < 10; i++) {
		long long res = go(0, i, (1 << i));
		ans = (ans + res) % MOD;
	}
	cout << ans % MOD << '\n';

	return 0;
}