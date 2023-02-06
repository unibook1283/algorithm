#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end());

	int ans = 0;
	for (int i = 0; i < n; i++) {
		int left = 0, right = n - 1;
		while (left < right) {
			if (left == i) {
				left++;
				continue;
			}
			if (right == i) {
				right--;
				continue;
			}
			if (v[left] + v[right] == v[i]) {
				ans++;
				break;
			}
			else if (v[left] + v[right] > v[i])
				right--;
			else
				left++;
		}
	}
	cout << ans << '\n';

	return 0;
}