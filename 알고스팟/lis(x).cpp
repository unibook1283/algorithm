#include <iostream>
#include <cstring>
using namespace std;
int n;
int a[501];
int cache[501];
int lis(int start) {
	int& ret = cache[start];
	if (ret != -1) return ret;
	ret = 1;
	for (int i = start + 1; i < n; i++) {
		if (a[start] < a[i]) {
			ret = max(ret, lis(i) + 1);
		}
	}
	return ret;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		memset(cache, -1, sizeof(cache));
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		cout << lis(0) << '\n';
	}

	return 0;
}