#include <iostream>
#include <vector>
using namespace std;
int get_gcd(int a, int b) {
	if (a == 0) return b;
	return get_gcd(b % a, a);
}
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	vector<int> diff(n - 1);
	for (int i = 0; i < n - 1; i++) {
		diff[i] = a[i + 1] - a[i];
	}
	int gcd = diff[0];
	for (int i = 1; i < n - 1; i++) {
		gcd = get_gcd(gcd, diff[i]);
	}

	int range = a[n - 1] - a[0];
	int total_count = range / gcd + 1;
	int res = total_count - n;
	cout << res << '\n';

	return 0;
}