#include <iostream>
using namespace std;
int a[10001];
int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (char ch : s) {
			a[i] |= (1 << (ch - 'a'));
		}
	}
	
	int rem_alpha = (1 << 26) - 1;
	for (int i = 0; i < m; i++) {
		int o;
		char x;
		cin >> o >> x;
		if (o == 1) {
			rem_alpha &= ~(1 << (x - 'a'));
		}
		else {
			rem_alpha |= (1 << (x - 'a'));
		}

		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (!(a[j] & ~rem_alpha)) cnt++;
		}
		cout << cnt << '\n';
	}

	return 0;
}