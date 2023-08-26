#include <iostream>
#include <algorithm>

using namespace std;

int a[200001];
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		if (n == 1) {
			if (a[0] == 1) cout << "YES\n";
			else cout << "NO\n";
			continue;
		}

		bool impossible = false;
		for (int i = 0; i < n; i++) {
			int cur_hegiht = a[i];
			int min_height = i + 1;
			int count = 0;
			count = upper_bound(a, a + n, min_height, greater<>()) - a;
			if (count != cur_hegiht) {
				impossible = true;
				break;
			}
		}
		if (impossible) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}