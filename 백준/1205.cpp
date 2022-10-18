#include <iostream>
using namespace std;
int a[51];
int main() {
	int n, s, p;
	cin >> n >> s >> p;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	if (n == p && s <= a[n - 1]) {
		cout << -1 << '\n';
		return 0;
	}
	int ans = n + 1;
	for (int i = 0; i < n; i++) {
		if (s >= a[i]) {
			ans = i + 1;
			break;
		}
	}
	cout << ans << '\n';

	return 0;
}