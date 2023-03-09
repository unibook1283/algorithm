#include <iostream>
using namespace std;
int a[1001][1001];
int main() {
	int n, m;
	cin >> n >> m;

	int zeros = 0;
	int ones = 0;
	bool leastOneAdj = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 0) zeros++;
			else ones++;
			if (i - 1 >= 0 && a[i - 1][j] == a[i][j])
				leastOneAdj = true;
			if (j - 1 >= 0 && a[i][j - 1] == a[i][j])
				leastOneAdj = true;
		}
	}
	if (zeros % 2 == 0 && ones % 2 == 0 && leastOneAdj)
		cout << 1 << '\n';
	else
		cout << -1 << '\n';

	return 0;
}