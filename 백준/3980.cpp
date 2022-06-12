#include <iostream>
#include <cstring>
using namespace std;
int a[11][11];
bool d[11];
int ans = 0;
void go(int index, int sum) {
	if (index == 11) {
		ans = max(ans, sum);
		return;
	}
	for (int i = 0; i < 11; i++) {
		if (a[index][i] == 0) continue;
		if (d[i] == false) {
			d[i] = true;
			go(index + 1, sum + a[index][i]);
			d[i] = false;
		}
	}
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		memset(d, false, sizeof(d));
		ans = 0;
		for (int i = 0; i < 11; i++) {
			for (int j = 0; j < 11; j++) {
				cin >> a[i][j];
			}
		}

		go(0, 0);
		cout << ans << '\n';
	}


	return 0;
}