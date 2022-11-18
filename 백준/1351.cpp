#include <iostream>
#include <map>
using namespace std;
long long p, q;
map<long long, long long> cache;
long long go(long long n) {
	if (n == 0) return 1;
	long long& ret = cache[n];
	if (ret != 0) return ret;
	return ret = go(n / p) + go(n / q);
}
int main() {
	long long n;
	cin >> n >> p >> q;
	cout << go(n) << '\n';

	return 0;
}