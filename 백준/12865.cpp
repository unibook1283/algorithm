#include <iostream>
using namespace std;
int w[101];
int v[101];
int d[101][100001];
int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> w[i] >> v[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			d[i][j] = d[i - 1][j];
			if (j - w[i] >= 0)
				d[i][j] = max(d[i][j], d[i - 1][j - w[i]] + v[i]);
		}
	}
	cout << d[n][k] << '\n';

	return 0;
}
/*
d[i][j]: i번째까지 봤을 때 무게가 j 이하인 것 중 최대 가치
*/