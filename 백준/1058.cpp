#include <iostream>
using namespace std;
int a[51][51];
const int INF = 987654321;
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char ch;
			cin >> ch;
			if (ch == 'Y') a[i][j] = 1;
			else a[i][j] = INF;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (j == k) continue;
				if (a[j][k] > a[j][i] + a[i][k]) {
					a[j][k] = a[j][i] + a[i][k];
				}
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (a[i][j] <= 2) cnt++;
		}
		ans = max(ans, cnt);
	}
	cout << ans << '\n';



	return 0;
}