#include <iostream>
#include <cstring>
using namespace std;
int a[1001];
int cache[1001];
int n;
int lis(int index) {
	if (index == n) return 1;
	int& ret = cache[index + 1];
	if (ret != -1) return ret;
	ret = 1;
	for (int next = index + 1; next < n; next++) {
		if (index == -1 || a[next] > a[index])
			ret = max(ret, 1 + lis(next));
	}
	return ret;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	memset(cache, -1, sizeof(cache));
	cout << lis(-1) - 1 << '\n';

	return 0;
}