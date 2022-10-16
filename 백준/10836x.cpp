#include <iostream>
using namespace std;
int map[701][701];
int m, n;
int main() {
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			map[i][j] = 1;
		}
	}
	while (n--) {
		int zero, one, two;
		cin >> zero >> one >> two;

		for (int i = m - 1; i >= 0; i--) {
			if (zero > 0) {
				zero--;
			}
			else if (one > 0) {
				map[i][0] += 1;
				one--;
			}
			else {
				map[i][0] += 2;
				two--;
			}
		}
		for (int i = 1; i < m; i++) {
			if (zero > 0) {
				zero--;
			}
			else if (one > 0) {
				for (int j = 0; j < m; j++) {
					map[j][i] += 1;
				}
				one--;
			}
			else {
				for (int j = 0; j < m; j++) {
					map[j][i] += 2;
				}
				two--;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}