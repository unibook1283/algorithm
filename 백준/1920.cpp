#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
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
		bool found = false;
		int x;
		cin >> x;
		int left = 0;
		int right = n - 1;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (v[mid] == x) {
				cout << "1\n";
				found = true;
				break;
			}
			else if (v[mid] > x) {
				right = mid - 1;
			}
			else left = mid + 1;
		}
		if (!found) cout << "0\n";
	}

	return 0;
}