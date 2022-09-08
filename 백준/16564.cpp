#include <iostream>
using namespace std;
long long a[1000001];
int main() {
	long long n, k;
	cin >> n >> k;
	long long left = 9876543211111, right = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		left = min(left, a[i]);
		right = max(right, a[i]);	
	}
	right += k;

	long long t = 0;
	while (left <= right) {
		long long mid = (left + right) / 2;
		long long sum = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] < mid) {
				sum += mid - a[i];
			}
		}
		if (sum > k) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
			t = mid;
		}
	}
	cout << t << '\n';

	return 0;
}