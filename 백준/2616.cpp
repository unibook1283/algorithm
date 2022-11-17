#include <iostream>
#include <cstring>
using namespace std;
int a[50001];
int cache[50001][4];
int n, m;
int go(int gaekcha_index, int small_car) {
	if (gaekcha_index >= n) return 0;
	int& ret = cache[gaekcha_index][small_car];
	if (ret != -1) return ret;
	ret = go(gaekcha_index + 1, small_car);
	if (small_car > 0) {
		int ret1 = go(gaekcha_index + m, small_car - 1);
		for (int j = 0; j < m; j++)
			if (gaekcha_index + j < n)
				ret1 += a[gaekcha_index + j];
			else break;
		ret = max(ret, ret1);
	}
	return ret;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> m;

	memset(cache, -1, sizeof(cache));
	cout << go(0, 3) << '\n';

	return 0;
}