#include <iostream>
#include <cstring>
using namespace std;
int n;
int cache[1001][2][3];
int go(int day, int late, int absence) {
	if (late >= 2 || absence >= 3) return 0;
	if (day == n) return 1;
	int& ret = cache[day][late][absence];
	if (ret != -1) return ret;
	ret = 0;
	ret += go(day + 1, late, 0);
	ret += go(day + 1, late + 1, 0);
	ret += go(day + 1, late, absence + 1);
	return ret % 1000000;
}
int main() {
	cin >> n;
	memset(cache, -1, sizeof(cache));
	cout << go(0, 0, 0) << '\n';

	return 0;
}