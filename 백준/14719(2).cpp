#include <iostream>
using namespace std;
int a[500];
int main() {
	int h, w;
	cin >> h >> w;
	for (int i = 0; i < w; i++) {
		cin >> a[i];
	}

	int ans = 0;
	for (int i = 1; i < w - 1; i++) {
		int lmax = 0;
		int rmax = 0;
		for (int j = 0; j < i; j++) {
			lmax = max(lmax, a[j]);
		}
		for (int j = i + 1; j < w; j++) {
			rmax = max(rmax, a[j]);
		}
		int height = min(lmax, rmax);
		if (height > a[i])
			ans += height - a[i];
	}

	cout << ans << '\n';

	return 0;
}