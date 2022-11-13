#include <iostream>
#include <cstring>
using namespace std;
long long cache[31][31];
long long go(int one, int half) {
	if (one == 0 && half == 0) return 1;
	long long& ret = cache[one][half];
	if (ret != -1) return ret;
	ret = 0;
	if (one > 0)
		ret += go(one - 1, half + 1);
	if (half > 0)
		ret += go(one, half - 1);
	return ret;
}
int main() {
	int n;
	memset(cache, -1, sizeof(cache));
	while (cin >> n) {
		if (n == 0) break;
		cout << go(n, 0) << '\n';
	}

	return 0;
}