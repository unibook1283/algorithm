#include <iostream>
using namespace std;
int main() {
	int x;
	cin >> x;
	int ans = 0;
	for (int i = 0; i < 6; i++) {
		if ((1 << i) & x) ans++;
	}
	if (ans == 0) ans++;
	cout << ans << '\n';

	return 0;
}