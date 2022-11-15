#include <iostream>
#include <cstring>
using namespace std;
int a[1001];
int cache[1001][1001];
int go(int start, int end, bool geun) {
	if (start > end) return 0;
	int& ret = cache[start][end];
	if (ret != -1) return ret;
	if (geun) {
		int x = a[start] + go(start + 1, end, false);
		int y = a[end] + go(start, end - 1, false);
		return ret = max(x, y);
	}
	else {
		int x = go(start + 1, end, true);
		int y = go(start, end - 1, true);
		return ret = min(x, y);
	}
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		memset(cache, -1, sizeof(cache));
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		cout << go(0, n - 1, true) << '\n';
	}

	return 0;
}