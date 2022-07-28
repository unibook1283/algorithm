#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		int m;
		cin >> m;
		for (int i = 0; i < m; i++) {
			int x;
			cin >> x;
			int left = 0, right = n - 1;
			bool found = false;
			while (left <= right) {
				int mid = (left + right) / 2;
				if (v[mid] > x) {
					right = mid - 1;
				}
				else if (v[mid] == x) {
					found = true;
					break;
				}
				else {
					left = mid + 1;
				}
			}
			if (found) cout << "1\n";
			else cout << "0\n";
		}
	}

	return 0;
}