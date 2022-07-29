#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int x;
	cin >> x;

	int left = 0, right = n - 1;
	int ans = 0;
	while (left < right) {
		int sum = a[left] + a[right];
		if (sum == x) {
			ans++;
			left++;
			right--;
		}
		else if (sum < x) left++;
		else right--;
	}
	cout << ans << '\n';


	return 0;
}