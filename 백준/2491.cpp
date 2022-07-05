#include <iostream>
using namespace std;
int a[100001];
int d[100001][2];	// 0: 오름, 1: 내림
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	d[0][0] = 1;
	d[0][1] = 1;
	for (int i = 1; i < n; i++) {
		if (a[i] >= a[i - 1]) d[i][0] = d[i - 1][0] + 1;
		else d[i][0] = 1;
		if (a[i] <= a[i - 1]) d[i][1] = d[i - 1][1] + 1;
		else d[i][1] = 1;
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			ans = max(ans, d[i][j]);
		}
	}
	cout << ans << '\n';
}