#include <iostream>
using namespace std;
int pSum[1001][1001][3];	// J, O, I
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int m, n, k;
	cin >> m >> n >> k;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			char ch;
			cin >> ch;
			pSum[i + 1][j + 1][0] = pSum[i][j + 1][0] + pSum[i + 1][j][0] - pSum[i][j][0];
			pSum[i + 1][j + 1][1] = pSum[i][j + 1][1] + pSum[i + 1][j][1] - pSum[i][j][1];
			pSum[i + 1][j + 1][2] = pSum[i][j + 1][2] + pSum[i + 1][j][2] - pSum[i][j][2];
			if (ch == 'J') {
				pSum[i + 1][j + 1][0]++;
			}
			else if (ch == 'O') {
				pSum[i + 1][j + 1][1]++;
			}
			else {
				pSum[i + 1][j + 1][2]++;
			}
		}
	}

	for (int i = 0; i < k; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		for (int j = 0; j < 3; j++) {
			cout << pSum[c][d][j] - pSum[a - 1][d][j] - pSum[c][b - 1][j] + pSum[a - 1][b - 1][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}