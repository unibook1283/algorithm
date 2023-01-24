#include <iostream>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int x, y;
		cin >> x >> y;
		int dist = y - x;

		int i = 1;
		int ans = 0;
		while (1) {
			if (dist <= i) {
				ans++;
				break;
			}
			else if (i < dist && dist <= 2 * i) {
				ans += 2;
				break;
			}
			else if (dist > 2 * i) {
				dist -= 2 * i;
				i++;
				ans += 2;
			}
		}
		cout << ans << '\n';
	}

	return 0;
}