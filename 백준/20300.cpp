#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<long long> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	long long m = 0;
	int left = 0, right = n - 1;
	if (n % 2 == 1) {
		m = v[n - 1];
		right--;
	}
	while (left < right) {
		long long sum = v[left++] + v[right--];
		m = max(m, sum);
	}
	cout << m << '\n';

	return 0;
}