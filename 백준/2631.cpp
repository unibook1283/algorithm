#include <iostream>
#include <cstring>
using namespace std;
int a[201];
int cache[201];
int n;
int lis(int start) {
	int& ret = cache[start];
	if (ret != -1) return ret;
	ret = 1;
	for (int next = start + 1; next < n; next++) {
		if (a[start] < a[next])
			ret = max(ret, lis(next) + 1);
	}
	return ret;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	memset(cache, -1, sizeof(cache));
	int max_len = 0;
	for (int i = 0; i < n; i++) {
		max_len = max(max_len, lis(i));
	}
	cout << n - max_len << '\n';

	return 0;
}