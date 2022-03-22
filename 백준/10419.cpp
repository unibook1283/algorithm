#include <iostream>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int d;
		cin >> d;
		int ans = 0;
		for (int i = 0; i < d; i++) {
			if (i + i * i <= d) {
				ans = i;
			}
			else break;
		}
		cout << ans << '\n';
	}


	return 0;
}