#include <iostream>
using namespace std;
int k[101];
int s[101];
int d[101][10001];
int main() {
	int n, t;
	cin >> n >> t;
	for (int i = 1; i <= n; i++) {
		cin >> k[i] >> s[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= t; j++) {
			d[i][j] = d[i - 1][j];
			if (j - k[i] >= 0) {
				d[i][j] = max(d[i][j], d[i - 1][j - k[i]] + s[i]);
			}
		}
	}
	cout << d[n][t] << '\n';

	return 0;
}