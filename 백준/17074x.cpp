#include <iostream>
#include <cstring>
using namespace std;
int a[100010];
int cache[100010][2];
int n;
int go(int index, int jump) {
	if (index == n) return 1;
	int& ret = cache[index][jump];
	if (ret != -1) return ret;
	if (index == n - 1)
		return ret = go(index + 1, jump);
	ret = 0;
	if (a[index] <= a[index + 1])
		ret += go(index + 1, jump);
	if (jump == 0 && a[index] <= a[index + 2])
		ret += go(index + 2, 1);
	return ret;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	a[n] = a[n + 1] = 1000000000;
	memset(cache, -1, sizeof(cache));
	cout << go(0, 0) << '\n';

	return 0;
}