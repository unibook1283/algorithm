#include <iostream>
#include <cstring>
using namespace std;
int cache[31][31];
int bino(int n, int k) {
	if (k == 1 || k == n) return 1;
	int& ret = cache[n][k];
	if (ret != -1) return ret;
	return ret = bino(n - 1, k - 1) + bino(n - 1, k);
}
int main() {
	int n, k;
	cin >> n >> k;
	memset(cache, -1, sizeof(cache));
	cout << bino(n, k) << '\n';

	return 0;
}