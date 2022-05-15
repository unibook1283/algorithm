#include <iostream>
using namespace std;
int main() {
	int n;
	while (cin >> n) {
		int num = 1;
		int cipher = 1;
		while (1) {
			if (num % n == 0) break;
			else {
				num = num * 10 + 1;
				cipher++;
				num %= n;
			}
		}
		cout << cipher << '\n';
	}

	return 0;
}