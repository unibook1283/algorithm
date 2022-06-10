#include <iostream>
using namespace std;
int a[51];
bool d[51][1001];
int main() {
	int n, s, m;
	cin >> n >> s >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	d[0][s] = true;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			int next;
			if (d[i - 1][j] == true) {
				next = j - a[i];
				if (next >= 0 && next <= m) {
					d[i][next] = true;
				}
				next = j + a[i];
				if (next >= 0 && next <= m) {
					d[i][next] = true;
				}
			}
		}
	}
	int ans = -1;
	for (int i = 0; i <= m; i++) {
		if (d[n][i] == true) ans = i;
	}
	cout << ans << '\n';

	return 0;
}