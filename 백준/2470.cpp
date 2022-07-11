#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<long long> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());

	long long ans[2];
	long long left = 0;
	long long right = n - 1;
	long long mini = 987654321111;
	while (left < right) {
		long long mid = a[left] + a[right];
		if (mini > abs(mid)) {
			mini = abs(mid);
			ans[0] = a[left];
			ans[1] = a[right];
			if (mid == 0) break;
		}
		if (mid < 0) left++;
		else right--;
	}
	cout << ans[0] << ' ' << ans[1] << '\n';




	return 0;
}