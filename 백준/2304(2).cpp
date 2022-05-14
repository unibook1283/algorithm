#include <iostream>
using namespace std;
int h[1001];
int main() {
	int n, ans = 0;
	cin >> n;

	int maxn, maxh = 0;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		h[x] = y;
		if (maxh < y) {
			maxh = y;
			maxn = x;
		}
	}
	ans += maxh;

	int height = 0;
	for (int i = 1; i < maxn; i++) {
		height = max(height, h[i]);
		ans += height;
	}

	height = 0;
	for (int i = 1000; i > maxn; i--) {
		height = max(height, h[i]);
		ans += height;
	}

	cout << ans << '\n';


	return 0;
}