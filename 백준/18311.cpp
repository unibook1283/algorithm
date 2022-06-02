#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n;
	long long k;
	long long sum = 0;
	int ans = -1;
	cin >> n >> k;
	vector<int> v(n);
	bool found = false;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		k -= v[i];
		if (k < 0) {
			cout << i + 1;
			found = true;
			return 0;
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		k -= v[i];
		if (k < 0) {
			cout << i + 1;
			break;
		}
	}

	return 0;
}