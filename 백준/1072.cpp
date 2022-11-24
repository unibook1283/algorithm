#include <iostream>
using namespace std;
const int MAX = 1000000000;
int main() {
	long long x, y;
	cin >> x >> y;
	long long z = y * 100 / x;
	long long left = 0, right = MAX;
	if (z >= 99) {
		cout << "-1\n";
		return 0;
	}
	while (left <= right) {
		long long mid = (left + right) / 2;
		long long nz = (y + mid) * 100 / (x + mid);
		if (nz > z)
			right = mid - 1;
		else
			left = mid + 1;
	}
	cout << left << '\n';

	return 0;
}