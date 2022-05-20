#include <iostream>
using namespace std;
int main() {
	int n, sum = 0;

	while (cin >> n) {
		if (sum + n >= 100) {
			if (100 - sum < sum + n - 100) break;
		}
		sum += n;
	}
	cout << sum << '\n';



	return 0;
}