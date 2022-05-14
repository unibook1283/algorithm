#include <iostream>
using namespace std;
int ans = 0;
int n;
int l[1001], h[1001];
void go(int maxn, int maxh, int lr) {	//lr=0 : 왼쪽, lr=1 : 오른쪽
	int next_mn;
	int next_mh = 0;
	for (int i = 0; i < n; i++) {
		if (lr == 0) {
			if (l[i] < maxn) {
				if (next_mh < h[i]) {
					next_mh = h[i];
					next_mn = l[i];
				}
			}
		}
		else {
			if (l[i] > maxn) {
				if (next_mh < h[i]) {
					next_mh = h[i];
					next_mn = l[i];
				}
			}
		}
	}
	if (next_mh == 0) return;

	int width;
	if (lr == 0) width = maxn - next_mn;
	else width = next_mn - maxn;
	ans += width * next_mh;

	go(next_mn, next_mh, lr);
}
int main() {
	cin >> n;

	int maxn, maxh = 0;
	for (int i = 0; i < n; i++) {
		cin >> l[i] >> h[i];
		if (maxh < h[i]) {
			maxn = l[i];
			maxh = h[i];
		}
	}
	ans += maxh;

	go(maxn, maxh, 0);
	go(maxn, maxh, 1);

	cout << ans << '\n';


	return 0;
}