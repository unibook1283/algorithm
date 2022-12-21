#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		sum += v[i];
	}
	if (sum % 3 != 0) {
		cout << "NO\n";
		return 0;
	}
	int two_count = 0;
	for (int i = 0; i < n; i++) {
		two_count += v[i] / 2;
	}
	if (two_count >= sum / 3) cout << "YES\n";
	else cout << "NO\n";

	return 0;
}