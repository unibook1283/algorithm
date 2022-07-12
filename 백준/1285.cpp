#include <iostream>
using namespace std;
char a[21][21];
char temp[21][21];
void flip(int x, int y) {
	if (temp[x][y] == 'H') temp[x][y] = 'T';
	else temp[x][y] = 'H';
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	int ans = 987654321;
	for (int state = 0; state < (1 << n); state++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				temp[i][j] = a[i][j];
			}
		}
		int sum = 0;
		for (int j = 0; j < n; j++) {
			int cnt = 0;
			for (int i = 0; i < n; i++) {
				if (state & (1 << i)) {
					flip(i, j);
				}
				if (temp[i][j] == 'H') cnt++;
			}
			sum += min(cnt, n - cnt);
		}
		ans = min(ans, sum);
	}

	cout << ans << '\n';


	return 0;
}