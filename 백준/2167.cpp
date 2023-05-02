#include <iostream>
using namespace std;
int pSum[301][301];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> pSum[i][j];
			pSum[i][j] += pSum[i - 1][j] + pSum[i][j - 1] - pSum[i - 1][j - 1];
		}
	}

	int k;
	cin >> k;
	while (k--) {
		int sx, sy, ex, ey;
		cin >> sx >> sy >> ex >> ey;
		sx--; sy--;
		int sum = pSum[ex][ey] - pSum[sx][ey] - pSum[ex][sy] + pSum[sx][sy];
		cout << sum << '\n';
	}

	return 0;
}