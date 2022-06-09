#include <iostream>
using namespace std;
int l[20];
int j[20];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> l[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> j[i];
	}
	
	int ans = 0;
	for (int i = 0; i < (1 << n); i++) {
		int health = 100;
		int joy = 0;
		for (int k = 0; k < n; k++) {
			if (i & (1 << k)) {
				health -= l[k];
				joy += j[k];
			}
		}
		if (health > 0) {
			ans = max(ans, joy);
		}
	}
	cout << ans << '\n';

	return 0;
}