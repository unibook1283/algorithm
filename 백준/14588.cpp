#include <iostream>
using namespace std;
int l[301], r[301];
int a[301][301];
const int INF = 987654321;
bool is_friend(int x, int y) {
	if (l[y] <= l[x] && l[x] <= r[y]) return true;
	if (l[x] <= l[y] && l[y] <= r[x]) return true;
	return false;
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> l[i] >> r[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) a[i][j] = INF;
		}
	}
	for (int i = 1; i <= n - 1; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (is_friend(i, j)) {
				a[i][j] = 1;
				a[j][i] = 1;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				a[j][k] = min(a[j][k], a[j][i] + a[i][k]);
			}
		}
	}
	int q;
	cin >> q;
	while (q--) {
		int aa, b;
		cin >> aa >> b;
		if (a[aa][b] == INF) cout << "-1\n";
		else cout << a[aa][b] << '\n';
	}

	return 0;
}