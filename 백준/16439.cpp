#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int a[30][30];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	vector<int> v;
	for (int i = 0; i < m - 3; i++) {
		v.push_back(0);
	}
	for (int i = 0; i < 3; i++) {
		v.push_back(1);
	}

	int ans = 0;
	do {
		int tot_sat = 0;
		for (int i = 0; i < n; i++) {
			int sat = 0;
			for (int j = 0; j < m; j++) {
				if (v[j] == 1) {
					sat = max(sat, a[i][j]);
				}
			}
			tot_sat += sat;
		}
		ans = max(ans, tot_sat);
	} while (next_permutation(v.begin(), v.end()));

	cout << ans << '\n';

	return 0;
}