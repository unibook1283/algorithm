#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());

	int score = 1;
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] >= score) {
			ans += a[i] - score;
			score++;
		}
	}
	cout << ans << '\n';

	return 0;
}