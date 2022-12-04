#include <iostream>
#include <cstring>
using namespace std;
int cache[10000001];
const int MOD = 10;
int hand_shake(int n) {
	if (n <= 1) return 1;
	int& ret = cache[n];
	if (ret != -1) return ret;
	ret = 0;
	ret = (ret + hand_shake(n - 2)) % MOD;
	ret = (ret + hand_shake(n - 1)) % MOD;
	return ret;
}
int main() {
	int n;
	cin >> n;
	memset(cache, -1, sizeof(cache));
	cout << hand_shake(n) << '\n';

	return 0;
}