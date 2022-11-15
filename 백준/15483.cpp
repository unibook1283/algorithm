#include <iostream>
#include <cstring>
using namespace std;
int cache[1001][1001];
string a, b;
int go(int ai, int bi) {
	if (ai == a.length()) return b.length() - bi;
	if (bi == b.length()) return a.length() - ai;
	if (a[ai] == b[bi]) return go(ai + 1, bi + 1);
	int& ret = cache[ai][bi];
	if (ret != -1) return ret;
	ret = 987654321;
	ret = min(ret, 1 + go(ai, bi + 1));
	ret = min(ret, 1 + go(ai + 1, bi));
	ret = min(ret, 1 + go(ai + 1, bi + 1));
	return ret;
}
int main() {
	cin >> a >> b;
	memset(cache, -1, sizeof(cache));
	cout << go(0, 0) << '\n';

	return 0;
}