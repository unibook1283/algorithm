#include <iostream>
using namespace std;
int main() {
	long long s, sum = 0, n = 1;
	cin >> s;

	while (sum <= s) {
		sum += n++;
	}
	cout << n - 2 << '\n';

	return 0;
}