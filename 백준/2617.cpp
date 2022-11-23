#include <iostream>
#include <set>
using namespace std;
int a[100][100];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int big, small;
		cin >> big >> small;
		big--; small--;
		a[big][small] = 1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (a[j][i] && a[i][k])
					a[j][k] = 1;
			}
		}
	}
	set<int> s;
	for (int i = 0; i < n; i++) {
		int cnt1 = 0;
		int cnt2 = 0;
		for (int j = 0; j < n; j++) {
			if (a[i][j]) cnt1++;
			if (a[j][i]) cnt2++;
		}
		if (cnt1 > n / 2) s.insert(i);
		if (cnt2 > n / 2) s.insert(i);
	}
	cout << s.size() << '\n';

	return 0;
}