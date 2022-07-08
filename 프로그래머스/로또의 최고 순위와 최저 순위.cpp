#include <iostream>
using namespace std;
int a[101][101];
int d[101][101];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			d[i][j] = 1;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i - 1 >= 0) {
				if (a[i][j] > a[i - 1][j])
					d[i][j] = max(d[i][j], d[i - 1][j] + 1);
				else
					d[i][j] = max(d[i][j], d[i - 1][j]);
			}
			if (j - 1 >= 0) {
				if (a[i][j] > a[i][j - 1])
					d[i][j] = max(d[i][j], d[i][j - 1] + 1);
				else
					d[i][j] = max(d[i][j], d[i][j - 1]);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << d[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << d[n - 1][n - 1];

	return 0;
}