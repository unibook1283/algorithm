#include <iostream>
using namespace std;
int pSum[1001][1001];
int main() {
	int r, c, q;
	cin >> r >> c >> q;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++) {
			int x;
			cin >> x;
			pSum[i + 1][j + 1] = pSum[i + 1][j] + pSum[i][j + 1] - pSum[i][j] + x;
		}

	for (int i = 0; i < q; i++) {
		int r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2;
		int sum = pSum[r2][c2] - pSum[r2][c1 - 1] - pSum[r1 - 1][c2] + pSum[r1 - 1][c1 - 1];
		int cnt = (r2 - r1 + 1) * (c2 - c1 + 1);
		cout << sum / cnt << '\n';
	}
	
	return 0;
}