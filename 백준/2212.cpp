#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n), interval(n - 1);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(a.begin(), a.end());
	int range = a.back() - a.front();

	for (int i = 0; i < n - 1; i++)
		interval[i] = a[i + 1] - a[i];

	sort(interval.begin(), interval.end(), greater<>());
	for (int i = 0; i < min(n - 1, k - 1); i++) {
		range -= interval[i];
	}

	cout << range << '\n';

	return 0;
}