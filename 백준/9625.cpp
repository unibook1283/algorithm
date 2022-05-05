#include <iostream>
#include <vector>
using namespace std;
int main() {
	int k;
	cin >> k;
	int a[46], b[46];
	a[0] = 1;
	b[0] = 0;
	for (int i = 1; i <= k; i++) {
		a[i] = b[i - 1];
		b[i] = a[i - 1] + b[i - 1];
	}
	cout << a[k] << ' ' << b[k] << '\n';

	return 0;
}