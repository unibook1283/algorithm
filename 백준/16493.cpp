#include <iostream>
using namespace std;
int d[21], p[21];
int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++)
		cin >> d[i] >> p[i];

	int ans = 0;
	for (int i = 0; i < (1 << m); i++) {
		int day = 0, page = 0;
		for (int j = 0; j < m; j++) {
			if (i & (1 << j)) {
				day += d[j];
				page += p[j];
			}
		}
		if (day <= n)
			ans = max(ans, page);
	}
	cout << ans << '\n';

	return 0;
}