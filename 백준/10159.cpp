#include <iostream>
using namespace std;
int a[101][101];
int cnt[101];
const int INF = 987654321;
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j) a[i][j] = INF;
		}
	}
	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;
		a[from - 1][to - 1] = 1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				a[j][k] = min(a[j][k], a[j][i] + a[i][k]);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] < INF) {
				cnt[i]++; cnt[j]++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << n - cnt[i] + 1 << '\n';
	}

	return 0;
}