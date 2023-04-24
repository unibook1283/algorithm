#include <iostream>
#include <cstring>
using namespace std;
int amount[4] = { 1,2,5,7 };
int cache[100001];
const int INF = 987654321;
int go(int n) {
	if (n == 0) return 0;
	else if (n < 0) return INF;
	int& ret = cache[n];
	if (ret != -1) return ret;
	ret = INF;
	for (int i = 0; i < 4; i++) {
		ret = min(ret, 1 + go(n - amount[i]));
	}
	return ret;
}
int main() {
	int n;
	cin >> n;

	memset(cache, -1, sizeof(cache));
	cout << go(n) << '\n';

	return 0;
}