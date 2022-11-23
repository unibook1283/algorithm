#include <iostream>
#include <cstring>
using namespace std;
bool check[101];
int cache[101][51];
int n, m;
int go(int day, int coupon) {
	if (day >= n + 1) return 0;
	int& ret = cache[day][coupon];
	if (ret != -1) return ret;
	ret = 987654321;
	if (check[day]) {
		ret = min(ret, go(day + 1, coupon));
	}
	else {
		if (coupon >= 3)
			ret = min(ret, go(day + 1, coupon - 3));
		ret = min(ret, 10000 + go(day + 1, coupon));
		ret = min(ret, 25000 + go(day + 3, coupon + 1));
		ret = min(ret, 37000 + go(day + 5, coupon + 2));
	}
	return ret;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		check[x] = true;
	}
	memset(cache, -1, sizeof(cache));
	cout << go(1, 0) << '\n';

	return 0;
}