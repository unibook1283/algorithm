#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int cur = n;
	for (int i = n - 1; i >= 0; i--) {
		if (v[i] == cur) {
			cur--;
		}
	}
	cout << cur << '\n';

	return 0;
}