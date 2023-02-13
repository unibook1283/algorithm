#include <iostream>
#include <cstring>
using namespace std;
int a[1001];
int cache[1001];
int n;
int go(int index) {
	if (index == n) return 0;
	int& ret = cache[index];
	if (ret != -1) return ret;
	ret = 0;
	int mini = 987654321, maxi = 0;
	for (int i = index; i < n; i++) {
		mini = min(mini, a[i]);
		maxi = max(maxi, a[i]);
		ret = max(ret, (maxi - mini) + go(i + 1));
	}
	return ret;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	memset(cache, -1, sizeof(cache));
	cout << go(0) << '\n';

	return 0;
}