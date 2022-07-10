#include <iostream>
using namespace std;
int t[100001];
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n - 2; i++) {
		cin >> t[i];
	}

	long long ans = 1;
	for (int i = 0; i < n - 2; i++) {
		int gcdv = gcd(ans, t[i]);
		ans = ans * t[i] / gcdv;
	}
	cout << ans << '\n';


	return 0;
}