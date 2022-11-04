#include <iostream>
#include <cstring>
using namespace std;
int skip;
const int M = 1000000000 + 100;
int bino[201][201];
void calcBino() {
	memset(bino, 0, sizeof(bino));
	for (int i = 0; i <= 200; i++) {
		bino[i][0] = bino[i][i] = 1;
		for (int j = 1; j < i; j++)
			bino[i][j] = min(M, bino[i - 1][j - 1] + bino[i - 1][j]);
	}
}
void go(int n, int m, string s) {
	if (skip < 0) return;
	if (n == 0 && m == 0) {
		if (skip-- == 0) cout << s << '\n';
		return;
	}
	if (bino[n + m][n] <= skip) {
		skip -= bino[n + m][n];
		return;
	}
	if (n > 0) go(n - 1, m, s + "-");
	if (m > 0) go(n, m - 1, s + "o");
}
int main() {
	int t;
	cin >> t;
	calcBino();
	while (t--) {
		int n, m;
		cin >> n >> m >> skip;
		skip--;
		go(n, m, "");
	}

	return 0;
}