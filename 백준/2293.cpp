#include <iostream>
#include <cstring>
using namespace std;
int a[101];
int cache[101][10001];
int n, k;
int go(int index, int sum) {
	if (index == n) {
		if (sum == k) return 1;
		else return 0;
	}
	int& ret = cache[index][sum];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; sum + i * a[index] <= k; i++) {
		ret += go(index + 1, sum + i * a[index]);
	}
	return ret;
}
int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	memset(cache, -1, sizeof(cache));
	cout << go(0, 0) << '\n';

	return 0;
}