#include <iostream>
using namespace std;
long long d[65][10];
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < 10; i++) {
		d[1][i] = 1;
	}
	for (int i = 2; i < 65; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k <= j; k++) {
				d[i][j] += d[i - 1][k];
			}
		}
	}

	while (t--) {
		int n;
		cin >> n;
		long long ans = 0;
		for (int i = 0; i < 10; i++) {
			ans += d[n][i];
		}
		cout << ans << '\n';
	}

	return 0;
}