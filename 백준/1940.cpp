#include <iostream>
#include <algorithm>
using namespace std;
int a[15001];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	
	int start = 0, end = n - 1;
	int ans = 0;
	while (start < end) {
		if (a[start] + a[end] == m) {
			ans++;
			start++;
			end--;
		}
		else if (a[start] + a[end] < m) {
			start++;
		}
		else end--;
	}
	cout << ans << '\n';

	return 0;
}